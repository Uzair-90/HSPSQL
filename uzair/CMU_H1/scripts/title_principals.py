import csv

input_file = '/Users/khan/Downloads/title.principals.tsv'
output_file = '/Users/khan/Downloads/newtitle.principals.tsv'

def preprocess_value(value):
    if value == '\\N':
        return None
    elif value.startswith('[') and value.endswith(']'):
        return value[1:-1]
    else:
        return value

with open(input_file, 'r', newline='') as file_in, open(output_file, 'w', newline='') as file_out:
    reader = csv.reader(file_in, delimiter='\t')
    writer = csv.writer(file_out, delimiter='\t')

    for row in reader:
        cleaned_row = [preprocess_value(value) for value in row]
        writer.writerow(cleaned_row)
