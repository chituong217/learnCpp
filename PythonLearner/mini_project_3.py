import torch
import torch.nn as nn
import torch.optim as optim


X = torch.tensor([[0,0], [0,1], [1,0], [1,1]], dtype=torch.float32)
y = torch.tensor([[0],     [1],     [1],     [0]], dtype=torch.float32)

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# Đẩy X lên GPU
X = X.to(device)
# [LỖ HỔNG 1]: Hãy viết clệnh đẩy đáp án y lên GPU
y = y.to(device)

# 2. XÂY DỰNG BỘ NÃO
class MangHocSau(nn.Module):
    def __init__(self):
        super().__init__()
        # [LỖ HỔNG 2]: Input X đang có 2 đặc trưng. Bạn hãy nối ống nước ở lớp này đi từ 2 Nơ-ron (đầu vào) bung rộng ra thành 8 Nơ-ron 
        self.lop1 = nn.Linear(2, 8) 
        
        self.lop2 = nn.Linear(8, 1) # Từ 8 nén lại ra 1 kết quả duy nhất
        self.relu = nn.ReLU()
        self.sigmoid = nn.Sigmoid() # Hàm này bóp nghẹt kết quả cuối cùng về đúng chuẩn từ 0 đến 1 (Xác suất)

    def forward(self, x):
        x = self.lop1(x)
        x = self.relu(x)
        x = self.lop2(x)
        x = self.sigmoid(x)
        return x

model = MangHocSau().to(device)

# 3. CHUẨN BỊ CÔNG CỤ DẠY HỌC
criterion = nn.BCELoss() # Hàm tính độ dốt (dành riêng cho Phân loại 0/1)
optimizer = optim.SGD(model.parameters(), lr=0.1) # Bộ sửa sai (lr: tốc độ học)

# 4. VÒNG LẶP HUẤN LUYỆN (1000 kiếp luân hồi)
for epoch in range(1000):
    y_pred = model(X)                # Bước 1: Dự đoán
    loss = criterion(y_pred, y)      # Bước 2: Tính độ dốt
    
    # [LỖ HỔNG 3]: Xóa trí nhớ/Làm sạch bộ nhớ để tránh Gradient Explosion! (Gợi ý: gọi hàm từ biến optimizer)
    optimizer.zero_grad()
    
    loss.backward()                  # Bước 4: Lan truyền ngược (Truy hô)
    optimizer.step()                 # Bước 5: Cập nhật nơ-ron

print("Đã học xong 1000 kiếp! Kết quả bói toán cuối cùng:")
# model(X) nhả ra xác suất (VD: 0.99). Dùng .round() để làm tròn thành 1 hoặc 0.
print(model(X).round())