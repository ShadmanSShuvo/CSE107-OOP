from PyPDF2 import PdfMerger
import os

pdf_files = [
    "Lecture 0 - Course Information.pdf",
    "Lecture 1 - Basic Features of OOP.pdf",
    "Lecture 2 - Encapsulation  Data Hiding.pdf",
    "Lecture 3 - Polymorphism.pdf",
    "Lecture 4 - Inheritance.pdf",
    "Lecture 5 - Exception Handling.pdf",
    "Lecture 6 Input - Output.pdf",
    "Lecture 7 Generic Class, STL and Collection Framework.pdf"
]

merger = PdfMerger()

for pdf in pdf_files:
    bookmark = os.path.splitext(os.path.basename(pdf))[0]
    merger.append(pdf, outline_item=bookmark)

merger.write("combined_with_bookmarks.pdf")
merger.close()