import csv

input_file = '/Users/khan/Downloads/remodified_title.akas.tsv'
output_file = '/Users/khan/Downloads/new_title.akas.tsv'

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

def preprocess_null_values(value):
    return None if value == '\\N' else value

with open(input_file, 'r', newline='') as file_in, open(output_file, 'w', newline='') as file_out:
    reader = csv.reader(file_in, delimiter='\t')
    writer = csv.writer(file_out, delimiter='\t')

    for row in reader:
        # Preprocess array columns
        row[5] = preprocess_array_values(row[5])
        row[6] = preprocess_array_values(row[6])

        # Preprocess null values
        row = [preprocess_null_values(value) for value in row]

        writer.writerow(row)
