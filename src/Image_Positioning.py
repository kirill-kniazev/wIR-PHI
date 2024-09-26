import sys
import os
import clr
sys.path.append("C:/Users/kuno/OneDrive - nd.edu/Documents/Soft_related/_Python Scripts/IR-PHI (widefield) 2022/photron_cam_Oct")
sys.path.append("C:/Users/kuno/OneDrive - nd.edu/Documents/Soft_related/_Python Scripts/IR-PHI_2021")
sys.path.append("C:/Users/kuno/OneDrive - nd.edu/Documents/Soft_related/_Python Scripts/IR-PHI_2021/laser_manipulator-test_June_2022/Newfocus")

#C:\Users\kuno\OneDrive - nd.edu\Documents\Soft_related\_Python Scripts\IR-PHI (widefield) 2022\wIR-PHI_base_on _laser_manipulator-test_June_2023\Madpiezo
sys.path.append("C:/Users/kuno/OneDrive - nd.edu/Documents/Soft_related/_Python Scripts/IR-PHI (widefield) 2022/wIR-PHI_base_on _laser_manipulator-test_June_2023/Madpiezo")
from datetime import datetime as dt
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QLineEdit, QLabel
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtCore import QTimer, QThread, pyqtSignal
import time
from madpiezo import Madpiezo

class LiveImageWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.coord_min_border = 0        # piezo stage coordinates, µm
        self.coord_max_border = 300      # piezo stage coordinates, µm
        self.initUI()
        self.piezo = Madpiezo()                 # Initialize piezo stage
        self.piezo_go_to_position(50, 50, 50)   # Move piezo stage to the initial position
        self.messageLabel.setText(f"Current position: x={self.x_coord} µm, y={self.y_coord} µm, z={self.z_coord} µm") 

    def initUI(self):
        # Create QLineEdit for piezo stage position input
        self.xInput = QLineEdit()
        self.xInput.setPlaceholderText(f"Enter x, µm ({self.coord_min_border}-{self.coord_max_border}):")
        self.yInput = QLineEdit()
        self.yInput.setPlaceholderText(f"Enter y, µm ({self.coord_min_border}-{self.coord_max_border}):")
        self.zInput = QLineEdit()
        self.zInput.setPlaceholderText(f"Enter z, µm ({self.coord_min_border}-{self.coord_max_border}):")

        # Create 'Move' button
        self.moveButton = QPushButton('Move stage')
        self.moveButton.clicked.connect(self.on_move_click)

        # Create QLabel for displaying messages
        self.messageLabel = QLabel()

        # Create layout and add canvas and button
        layout = QVBoxLayout()
        layout.addWidget(self.xInput)
        layout.addWidget(self.yInput)
        layout.addWidget(self.zInput)
        layout.addWidget(self.moveButton)
        layout.addWidget(self.messageLabel)            # Add message label to layout
        self.setLayout(layout)

    def piezo_go_to_position(self, x, y, z):
        """
        1. Set coords for piezo stage.
        2. Then some "sleep" to reach position.
        3. Read and print current position.
        """
        self.piezo.goxy(x, y)
        self.piezo.goz(z)
        time.sleep(1)

        coords = self.piezo.get_position()
        self.x_coord = round(coords[0], 2)
        self.y_coord = round(coords[1], 2)
        self.z_coord = round(coords[2], 2)

    def on_move_click(self):
        x, y, z = float(self.xInput.text()), float(self.yInput.text()), float(self.zInput.text())
        if self.coord_min_border <= x <= self.coord_max_border and \
           self.coord_min_border <= y <= self.coord_max_border and \
           self.coord_min_border <= z <= self.coord_max_border:
            self.piezo_go_to_position(x, y, z)
            self.messageLabel.setText(f"Current position: x={self.x_coord} µm, y={self.y_coord} µm, z={self.z_coord} µm")
        else:
            self.messageLabel.setText("Range values are bad")

    def update_message(self, message):
        self.messageLabel.setText(f"<font color='green'>{message}</font>")

    def closeEvent(self, event): 
        self.piezo_go_to_position(50, 50, 50)
        self.piezo.mcl_close()      # Disconnect piezo stage
        event.accept()              # Close window


app = QApplication(sys.argv)
live_image_window = LiveImageWindow()
live_image_window.show()
sys.exit(app.exec_())