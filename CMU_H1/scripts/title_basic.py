import csv

input_file = '/Users/khan/Downloads/retitle.basics.tsv'
output_file = '/Users/khan/Downloads/new_title.basics.tsv'



def preprocess_null_values(value):
    return None if value == '\\N' else value

with open(input_file, 'r', newline='') as file_in, open(output_file, 'w', newline='') as file_out:
    reader = csv.reader(file_in, delimiter='\t')
    writer = csv.writer(file_out, delimiter='\t')

    # Read the header row
    header = next(reader)

    # Write the modified header to the output file
    writer.writerow(header)

    for row in reader:
        modified_row = [preprocess_null_values(value) for value in row]
        writer.writerow(modified_row)
