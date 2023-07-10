import csv

input_file = '/Users/khan/Downloads/name.basics.tsv'
output_file = '/Users/khan/Downloads/modified_name.basics.tsv'

with open(input_file, 'r', newline='') as file_in, open(output_file, 'w', newline='') as file_out:
    reader = csv.reader(file_in, delimiter='\t')
    writer = csv.writer(file_out, delimiter='\t')

    for row in reader:
        row[4] = '{' + row[4] + '}' if row[4] != '\\N' else '{}'
        row[5] = '{' + row[5] + '}' if row[5] != '\\N' else '{}'
        row[2] = row[2] if row[2] != '\\N' else None
        row[3] = row[3] if row[3] != '\\N' else None
        writer.writerow(row)
