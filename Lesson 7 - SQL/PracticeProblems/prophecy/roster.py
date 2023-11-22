from cs50 import SQL
import csv

db = SQL("sqlite:///roster.db")

# Step 1: Create tables as per your schema
# db.execute("CREATE TABLE IF NOT EXISTS students (id INT, student_name TEXT, PRIMARY KEY(id))")
# db.execute("CREATE TABLE IF NOT EXISTS houses (id INT, house TEXT, head TEXT, PRIMARY KEY(id))")
# db.execute("CREATE TABLE IF NOT EXISTS studentHouse (id INT, student_id INT, house_id INT, PRIMARY KEY(id), FOREIGN KEY(student_id) REFERENCES students(id), FOREIGN KEY(house_id) REFERENCES houses(id))")

# Step 2: Read and process CSV data
""" with open("students.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        # Insert into students
        db.execute(
            "INSERT INTO students (id, student_name) VALUES (:id, :name)",
            id=row["id"],
            name=row["student_name"],
        )

        # Insert into houses (ensure no duplicate house entries)
        if (
            db.execute("SELECT * FROM houses WHERE house = :house", house=row["house"])
            == []
        ):
            db.execute(
                "INSERT INTO houses (house, head) VALUES (:house, :head)",
                house=row["house"],
                head=row["head"],
            ) """

# After populating students and houses, populate studentHouse
""" db.execute("CREATE TABLE IF NOT EXISTS new_houses (id INTEGER PRIMARY KEY AUTOINCREMENT, house TEXT, head TEXT)")
houses = db.execute("SELECT house, head FROM houses")
for house in houses:
    db.execute("INSERT INTO new_houses (house, head) VALUES (:house, :head)", house=house["house"], head=house["head"])
db.execute("DROP TABLE houses")
db.execute("ALTER TABLE new_houses RENAME TO houses") """

students = db.execute("SELECT * FROM students")
houses = db.execute("SELECT * FROM houses")

# Reading from the CSV and populating studentHouse
""" with open("students.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        # Get student ID from the students table
        student_id = db.execute(
            "SELECT id FROM students WHERE student_name = :name",
            name=row["student_name"],
        )[0]["id"]

        # Get house ID from the houses table
        house_id = db.execute(
            "SELECT id FROM houses WHERE house = :house", house=row["house"]
        )[0]["id"]

        # Insert into studentHouse
        db.execute(
            "INSERT INTO studentHouse (student_id, house_id) VALUES (:student_id, :house_id)",
            student_id=student_id,
            house_id=house_id,
        ) """

studentHouse = db.execute("SELECT * FROM studentHouse")
print(studentHouse)