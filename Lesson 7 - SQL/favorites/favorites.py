""" import csv
from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()
    counts.update(row["problem"] for row in reader)


favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite.capitalize()]}") """

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

#allData = db.execute("SELECT * FROM favorites LIMIT 10;")
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?;", favorite)
row = rows[0]

print(rows)