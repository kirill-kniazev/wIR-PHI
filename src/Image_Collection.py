import sys
import os
import clr
from pathlib import Path

from CMOS_Functions import PhotronCamera
import Firefly_SW as Firefly_SW         # Shoert Wavelngth Firefly laser controll class. Laser IP - 192.168.1.229
import Firefly_LW as Firefly_LW         # Long   Wavelngth Firefly laser controll class. Laser IP - 192.168.1.231

# Import custom classes to controll Newfocus Conex-CC close loop controller used for mirror angle correction
import clr
clr.AddReference(str(Path(__file__).resolve().parent / "Newfocus" / "Newport.CONEXCC.CommandInterface.dll"))
import CommandInterfaceConexCC
from Newfocus.ConexCC import ConexCC

from matplotlib.colors import ListedColormap
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
from scipy import interpolate
from datetime import datetime as dt
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QLineEdit
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtCore import QTimer
import time


class MplCanvas(FigureCanvas):
    def __init__(self):
        self.fig = Figure()
        self.ax = self.fig.add_subplot(111)
        super(MplCanvas, self).__init__(self.fig)

class LiveImageWindow(QWidget):
    def __init__(self, camera):
        super().__init__()
        self.camera = camera
        self.ff3 = Firefly_LW.Firefly_LW(sock=None) # initialyze long WL laser
        self.conexcc = ConexCC(com_port='COM3', velocity=0.5)
        self.initUI()

        hex_colors = [
            "#000000", "#000005", "#00000a", "#00000f", "#000014", "#00001a", "#00001f", "#000024", 
            "#000029", "#00002e", "#000034", "#000039", "#00003e", "#000043", "#000048", "#00004e", 
            "#000053", "#000058", "#00005d", "#000062", "#000068", "#00006d", "#000072", "#000077", 
            "#00007c", "#000082", "#000087", "#00008c", "#000091", "#000096", "#00009c", "#0000a1", 
            "#0000a6", "#0000ab", "#0000b0", "#0000b6", "#0000bb", "#0000c0", "#0000c5", "#0000ca", 
            "#0000d0", "#0000d5", "#0000da", "#0000df", "#0000e4", "#0000ea", "#0000ef", "#0000f4", 
            "#0400f9", "#0900ff", "#0e00fa", "#1300f5", "#1700ef", "#1c00ea", "#2100e4", "#2600df", 
            "#2a00da", "#2f00d4", "#3400cf", "#3900c9", "#3d00c4", "#4200be", "#4700b9", "#4c00b4", 
            "#5100ae", "#5100a9", "#5100a3", "#51009e", "#510098", "#510093", "#51008e", "#510088", 
            "#500083", "#50007d", "#500078", "#500072", "#50006d", "#500068", "#500062", "#4f005d", 
            "#540057", "#590052", "#5e004c", "#630047", "#680042", "#6d003c", "#720037", "#770031", 
            "#7c002c", "#810026", "#860021", "#8b001c", "#900016", "#950011", "#9a000b", "#9f0006", 
            "#a40000", "#a90000", "#ae0000", "#b40000", "#b90000", "#be0000", "#c40000", "#c90000", 
            "#ce0000", "#d40000", "#d90000", "#de0000", "#e40000", "#e90000", "#ff0000", "#ff0000", 
            "#ff0000", "#ff0000", "#ff0500", "#ff0a00", "#ff1000", "#ff1500", "#ff1b00", "#ff2000", 
            "#ff2500", "#ff2b00", "#ff3000", "#ff3600", "#ff3b00", "#ff4000", "#ff4600", "#ff4b00", 
            "#ff5100", "#ff5504", "#ff5a09", "#ff5f0e", "#ff6413", "#ff6918", "#ff6d1c", "#ff7221", 
            "#ff7726", "#ff7c2b", "#ff8130", "#ff8635", "#ff8a39", "#ff8f3e", "#ff9443", "#ff9948", 
            "#ff9e4d", "#ffa352", "#ffa34d", "#ffa347", "#ffa341", "#ffa33b", "#ffa335", "#ffa32f", 
            "#ffa329", "#ffa324", "#ffa31e", "#ffa318", "#ffa312", "#ffa30c", "#ffa306", "#ffa300", 
            "#ffa300", "#ffa300", "#ffa300", "#f8a300", "#f0a300", "#e8a300", "#e1a300", "#d9a300", 
            "#d1a300", "#caa300", "#c2a300", "#baa300", "#b3a300", "#aba300", "#a3a300", "#a8a300",
            "#ada300", "#b2a903", "#b7af06", "#bcb509", "#c1bb0c", "#c6c110", "#cbc713", "#d1cd16",
            "#d6d419", "#dbda1d", "#e0e020", "#e5e623", "#eaec26", "#eff229", "#f4f82d", "#f9ff30",
            "#ffff33", "#ffff36", "#ffff3a", "#ffff3d", "#ffff40", "#ffff43", "#ffff47", "#ffff4a",
            "#ffff4d", "#ffff50", "#ffff53", "#ffff57", "#ffff5a", "#ffff5d", "#ffff60", "#ffff64", 
            "#ffff67", "#ffff6a", "#ffff6d", "#ffff70", "#ffff74", "#ffff77", "#ffff7a", "#ffff7d", 
            "#ffff81", "#ffff84", "#ffff87", "#ffff8a", "#ffff8e", "#ffff91", "#ffff94", "#ffff97",
            "#ffff9a", "#ffff9e", "#ffffa1", "#ffffa4", "#ffffa7", "#ffffab", "#ffffae", "#ffffb1",
            "#ffffb4", "#ffffb7", "#ffffbb", "#ffffbe", "#ffffc1", "#ffffc4", "#ffffc8", "#ffffcb",
            "#ffffce", "#ffffd1", "#ffffd5", "#ffffd8", "#ffffdb", "#ffffde", "#ffffe1", "#ffffe5",
            "#ffffe8", "#ffffeb", "#ffffee", "#fffff2", "#fffff5", "#fffff8", "#fffffb", "#ffffff"
        ]
        rgb_colors = [mpl.colors.hex2color(color) for color in hex_colors]
        self.cmap = ListedColormap(rgb_colors)

    def initUI(self):
        # Create canvas for image
        self.canvas = MplCanvas()  

        # Create QLineEdit for wavenumber input
        self.WLInput = QLineEdit()
        self.WLInput.setPlaceholderText(f"Enter ν, cm⁻¹ (1041-1840):")

        # Create 'Apply' button
        self.applyButton = QPushButton('Apply parameters')
        self.applyButton.clicked.connect(self.on_apply_click)

        # Create 'Go' button
        self.goButton = QPushButton('Collect IR image')
        self.goButton.clicked.connect(self.on_go_click)
        self.goButton.setEnabled(False)

        # Create 'Resume' button
        self.resumeButton = QPushButton('Live image')  
        self.resumeButton.clicked.connect(self.on_resume_click)
        self.resumeButton.setEnabled(False)

        # Create 'Save' button
        self.saveButton = QPushButton('Save') 
        self.saveButton.clicked.connect(self.on_save_click)
        self.saveButton.setEnabled(False)

        # Create QLineEdit for sample name input
        self.sampleNameInput = QLineEdit()
        self.sampleNameInput.setPlaceholderText("Enter sample name")

        # Create layout and add canvas and button
        layout = QVBoxLayout()
        layout.addWidget(self.canvas)
        layout.addWidget(self.WLInput)                 # Add sample wavenumber input to layout
        layout.addWidget(self.applyButton)
        layout.addWidget(self.goButton)
        layout.addWidget(self.resumeButton)
        layout.addWidget(self.sampleNameInput)         # Add sample name input to layout
        layout.addWidget(self.saveButton)
        self.setLayout(layout)

        # Create QTimer object for updating image
        self.timer = QTimer()
        self.timer.setInterval(int(1000 / 60))         # Set interval to 60 fps
        self.timer.timeout.connect(self.update_image)  # Connect timeout to function
        self.timer.start()                             # Start timer

        self.setWindowTitle('Image Collection')

    def update_image(self):
        self.image = self.camera.getLiveImage_Mod(bufferSize=(256, 256), Flip=True, y1=117, y2=193, x1=57, x2=133)
        self.canvas.ax.clear()                                       # Clear previous image
        im = self.canvas.ax.imshow(self.image, cmap="gray")
        self.cbar = self.canvas.fig.colorbar(im, ax=self.canvas.ax)  # Create colorbar
        self.cbar.set_label("CMOS counts")                           # Add colorbar title
        self.canvas.ax.set_xticks([])                                # Remove x-axis ticks
        self.canvas.ax.set_yticks([])                                # Remove y-axis ticks
        self.canvas.draw()
        self.cbar.remove()                                           # Update colorbar

    def Intrapolation(self, image_size, input_image):
        x = np.linspace(0, 1, image_size)
        y = np.linspace(0, 1, image_size)

        x2 = np.linspace(0, 1, image_size*2)
        y2 = np.linspace(0, 1, image_size*2)

        f = interpolate.interp2d(x, y, input_image, kind = 'cubic')
        return f(x2, y2)

    def PlotImages(self):
        self.image = self.camera.returnFinalImage_Mod(num_of_images=5456,start_image=0, Flip=True, y1=117, y2=193, x1=57, x2=133)   # Capture image from camera
        self.intrapolated_image = self.Intrapolation(np.shape(self.image)[0], self.image)
        self.canvas.ax.clear()
        im = self.canvas.ax.imshow(self.intrapolated_image, cmap=self.cmap)
        self.cbar = self.canvas.fig.colorbar(im, ax=self.canvas.ax)  # Create colorbar
        self.cbar.set_label("wIR-PHI signal (a. u.)")                # Add colorbar title
        self.canvas.ax.set_xticks([])                                # Remove x-axis ticks
        self.canvas.ax.set_yticks([])                                # Remove y-axis ticks

        self.canvas.draw()

    def mirror_go_to_position_wevelength_corection(self, wevelength):
        """
        1. Read following wavelength
        2. Use the mirror position correction from the table
        3. Set absolute position for mirror
        4. Then some "sleep" to reach the position.
        5. Read and write current position.
        """
        # Define wavelength ranges and corresponding values
        wavelength_ranges = [
            ((1041, 1315), 1.582),
            ((1316, 1375), 1.580),
            ((1376, 1629), 1.577),
            ((1630, 1689), 1.577),
            ((1690, 1709), 1.57),
            ((1710, 1712), 1.575),
            ((1713, 1714), 1.566),
            ((1715, 1716), 1.56),
            ((1717, 1724), 1.556),
            ((1725, 1734), 1.551),
            ((1735, 1744), 1.56),
            ((1745, 1759), 1.542),
            ((1760, 1769), 1.537),
            ((1770, 1784), 1.533),
            ((1785, 1794), 1.53),
            ((1795, 1804), 1.535),
            ((1805, 1827), 1.54),
            ((1828, 1835), 1.545),
        ]

        # Find the correct value for the given wavelength
        for (low, high), value in wavelength_ranges:
            if low <= wevelength <= high:
                d = value
                break

        self.conexcc.move_absolute(d)
        time.sleep(1)

    def on_apply_click(self):
        if self.WLInput.text():  # Check if the QLineEdit widgets are not empty
            if 1041 <= int(self.WLInput.text()) <= 1840:
                self.ff3.go_to_wavelength(int(self.WLInput.text())) # Select laser wavelength
                self.mirror_go_to_position_wevelength_corection(int(self.WLInput.text()))
                time.sleep(0.5)                                     # Time to change wavelength
                self.goButton.setEnabled(True)

    def on_go_click(self):
        self.timer.stop()                                   # Stop updating image
        self.PlotImages()
        self.applyButton.setEnabled(False)
        self.goButton.setEnabled(False)
        self.resumeButton.setEnabled(True)
        self.saveButton.setEnabled(True)    

    def on_resume_click(self):
        self.cbar.remove()                  # Remove wIR-PHI colorbar
        self.timer.start()                  # Resume updating image
        self.applyButton.setEnabled(True)
        self.goButton.setEnabled(True)
        self.resumeButton.setEnabled(False)
        self.saveButton.setEnabled(False)

    def on_save_click(self):
        cur_time = dt.now()                                                                                                               # Get current time
        f_name_prefix = f'[{cur_time.year}-{cur_time.month}-{cur_time.day}@{cur_time.hour:02d}-{cur_time.minute:02d}]'                    # Format file name prefix with current time
        dir_name = f"C:\\Users\\kuno\\OneDrive - nd.edu\\Documents\\Measurements\\wIR-PHI_maps\\{f_name_prefix}_{self.sampleNameInput.text()}_{self.WLInput.text()}_cm⁻¹" # Define directory name
        if os.path.exists(dir_name) and os.listdir(dir_name):   # Check if folder already exists and is not empty
            dir_name = dir_name + "_1"                          # Change folder name if folder is not empty
        os.makedirs(dir_name, exist_ok=True)                    # Create directory
        np.savetxt(f"{dir_name}\\{f_name_prefix}_raw.csv", self.image, delimiter=",")                       # Safe data
        np.savetxt(f"{dir_name}\\{f_name_prefix}.csv", self.intrapolated_image, delimiter=",")              # Safe data
        self.goButton.setEnabled(False)
        self.saveButton.setEnabled(False) 

    def closeEvent(self, event): 
        self.timer.stop()                           # Stop updating image
        self.camera.closeCamera()                   # Disconnect camera
        self.conexcc.close()                        # Disconnect mirror
        event.accept()                              # Close window

app = QApplication(sys.argv)
camera = PhotronCamera()                            # Initialize camera
live_image_window = LiveImageWindow(camera)
live_image_window.show()
sys.exit(app.exec_())