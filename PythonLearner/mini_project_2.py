import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression

du_lieu_benh_vien = {
    "Kich_Thuoc_mm": [1.2, 5.5, 2.1, 8.0, 1.5, 6.2, 1.8, 9.1, 2.5, 7.5],
    "Do_Cung": [10, 85, 15, 90, 12, 88, 20, 95, 18, 80],
    "Mau_Sac": ["Nhat", "Dam", "Nhat", "Dam", "Nhat", "Dam", "Nhat", "Dam", "Nhat", "Dam"],
    "Ac_Tinh": [0, 1, 0, 1, 0, 1, 0, 1, 0, 1]  # 1 là Ác tính, 0 là Lành tính
}

df = pd.DataFrame(du_lieu_benh_vien)
df = pd.get_dummies(df, columns=["Mau_Sac"])
y = df["Ac_Tinh"]
X = df.drop(columns=["Ac_Tinh"])

scaler = StandardScaler()
X = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = LogisticRegression()

model.fit(X_train, y_train)

score = model.score(X_test, y_test)

print(score)

