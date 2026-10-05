import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression

du_lieu = {
    "Tuoi": [22, 25, 47, 52, 46, 56],
    "Luong_Thang": [15000000, 20000000, 45000000, 50000000, 42000000, 60000000],
    "Gioi_Tinh": ["Nam", "Nu", "Nu", "Nam", "Nam", "Nu"],
    "Mua_VIP": [0, 0, 1, 1, 1, 1]
}

df = pd.DataFrame(du_lieu)

df = pd.get_dummies(df, columns=["Gioi_Tinh"])

y = df["Mua_VIP"]

X = df.drop(columns=["Mua_VIP"])

scaler = StandardScaler()

X_after = scaler.fit_transform(X)

mo_hinh = LogisticRegression()

mo_hinh.fit(X_after, y)

diem_so = mo_hinh.score(X_after, y)

print(diem_so)

ket_qua = mo_hinh.predict(X_after)

print(ket_qua)