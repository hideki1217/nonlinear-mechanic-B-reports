from pathlib import Path

import matplotlib.pyplot as plt
import numpy as np

def main(input_file: Path) -> None:
    data = np.loadtxt(input_file, delimiter=" ")
    
    plt.plot(data[:, 0], data[:, 1])
    plt.ylim((0, 1))
    plt.savefig(f"{input_file.stem}.png")
    plt.close()


if __name__ == "__main__":
    import sys
    
    if len(sys.argv) != 2:
        raise RuntimeError("")
    
    input_file = Path(sys.argv[1])
    
    main(input_file)
    