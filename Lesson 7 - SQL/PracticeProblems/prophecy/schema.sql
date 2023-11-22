CREATE TABLE students (
    id INT,
    student_name TEXT,
    PRIMARY KEY(id)
)

CREATE TABLE houses (
    id INT,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE studentHouse (
    id INT,
    student_id INT,
    house_id INT,
    PRIMARY KEY(id),
    FOREIGN KEY(student_id) REFERENCES new_students(id),
    FOREIGN KEY(house_id) REFERENCES houses(id)
)
