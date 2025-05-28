import os
from PyPDF2 import PdfMerger

folder_path = "/Users/shuvo/Documents/CSE107-OOP/Theory"
pdf_files = sorted([f for f in os.listdir(folder_path) if f.endswith(".pdf")])

merger = PdfMerger()

for pdf in pdf_files:
    full_path = os.path.join(folder_path, pdf)
    bookmark = os.path.splitext(pdf)[0]
    merger.append(full_path, outline_item=bookmark)

merger.write(os.path.join(folder_path, "merged_output.pdf"))
merger.close()