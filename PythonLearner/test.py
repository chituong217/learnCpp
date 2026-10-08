import torch
import torch.nn as nn

class MangNoronNhanDienChuSo(nn.Module):
    def __init__(self):
        super().__init__()

        self.lop1 = nn.Linear(784, 256)

        self.lop2 = nn.Linear(256, 64)

        self.lop3 = nn .Linear(64, 10)

        self.relu = nn.ReLU()


    def forward(self, x):
        x = self.lop1(x)
        x = self.relu(x)
        x = self.lop2(x)
        x = self.relu(x)
        x = self.lop3(x)

        return x