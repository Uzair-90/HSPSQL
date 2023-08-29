import csv

input_file = '/Users/khan/Downloads/title.crew.tsv'
output_file = '/Users/khan/Downloads/modified_title.crew.tsv'

def preprocess_array_values(value):
    if value == '\\N':
        return '{}'
    else:
        if value.startswith('{') and value.endswith('}'):
            # Remove the outer curly braces
            value = value[1:-1]
            # Check if the value is empty
            if value.strip() == '':
                return '{}'
        return '{' + value + '}'

with open(input_file, 'r', newline='') as file_in, open(output_file, 'w', newline='') as file_out:
    reader = csv.reader(file_in, delimiter='\t')
    writer = csv.writer(file_out, delimiter='\t')

    for row in reader:
        row[1] = preprocess_array_values(row[1])  # directors column
        row[2] = preprocess_array_values(row[2])  # writers column
        writer.writerow(row)
