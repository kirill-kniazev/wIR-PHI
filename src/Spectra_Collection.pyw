import os
from pathlib import Path

# Path to the script to run
script_dir = Path(__file__).resolve().parent
script_path = script_dir / "Spectra_Collection.py"

# Command to run the script
command = f"python \"{script_path}\""

# Execute the command
os.system(command)
