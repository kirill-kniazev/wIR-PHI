# Optimized for the square masaics only

import numpy as np
import matplotlib.pyplot as plt
import tkinter as tk
from tkinterdnd2 import TkinterDnD, DND_FILES
import os
import re

# (GUI) Get file path and folder path from the user using a drag-and-drop interface and impoer the data
def get_file_and_folder_path():
    def drop(event):                            # Function to handle the drop event
        file_path = event.data.strip('{}')      # Remove curly braces from the path if they exist
        folder_path = os.path.dirname(file_path)# Get the folder path
        file_path_var.set(file_path)            # Store the values in the tkinter variables
        folder_path_var.set(folder_path)
        DnD.quit()                              # Close the window
        DnD.destroy()
    DnD = TkinterDnD.Tk()                       # Create a TkinterDnD window
    DnD.title('Open the file')
    file_path_var = tk.StringVar()              # Variables to store file and folder paths
    folder_path_var = tk.StringVar()
    frame = tk.Frame(DnD, width=400, height=200)# Create a frame inside the window
    frame.pack_propagate(False)
    frame.pack()
    label = tk.Label(frame, text="Drag and drop a .pny file here", bg='lightgrey') # Create a label with instructions
    label.pack(fill=tk.BOTH, expand=True)
    label.drop_target_register(DND_FILES)       # Register the label as a drop target for files
    label.dnd_bind('<<Drop>>', drop)            # Bind the drop event to the function
    DnD.mainloop()                              # Start the TkinterDnD main loop
    return file_path_var.get(), folder_path_var.get()   # Return both the file and folder paths after the window closes
file_path, folder_path = get_file_and_folder_path()     # Call the function and retrieve the file and folder paths

image_stack = np.load(file_path)                # Load the stack of images from the .npy file

# Gather the metadata from the file name and calculate the size of the images and mosaic
def extract_values(file_path):                  # Gather the metadata from the file name
    match = re.search(r"\[x-(\d+)-(\d+)-(\d+)\]\[y-(\d+)-(\d+)-(\d+)\]", file_path)
    if match:
        x_start = int(match.group(1))
        x_end = int(match.group(2))
        width = int(match.group(3))
        y_start = int(match.group(4))
        y_end = int(match.group(5))
        height = int(match.group(6))
        return x_start, x_end, width, y_start, y_end, height
    else:
        raise ValueError("No match found")
x_start, x_end, scanning_width, y_start, y_end, scanning_height = extract_values(file_path)
image_size = image_stack.shape[1]               # Get the size of the images in the stack
mosaic_size = (x_end-x_start)//scanning_width   # Number of images along each axis of the mosaic

# Reassemble the mosaic by placing each image in its correct position
full_mosaic = np.zeros((mosaic_size * image_size, mosaic_size * image_size))
for idx in range(image_stack.shape[0]):         # Loop through the image stack and place each image in its correct position
    row = idx // mosaic_size            # Compute the row and column position in the mosaic
    col = idx % mosaic_size
    full_mosaic[row * image_size:(row + 1) * image_size, col * image_size:(col + 1) * image_size] = image_stack[idx] # Place the image into the correct position in the mosaic

# Display the reassembled mosaic
plt.imshow(full_mosaic, cmap='viridis', aspect='auto')
plt.colorbar()
plt.title("Reassembled Mosaic")
plt.show()

results_path = f"{folder_path}/{os.path.splitext(os.path.basename(file_path))[0]}_mosaic.txt"
np.savetxt(results_path, full_mosaic)                 # Save the assembled mosaic as a .txt file


# Image processing block: