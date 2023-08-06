require 'fiddle/import'

module Part3
  extend Fiddle::Importer
  dlload '/Users/khan/Desktop/database/part3.so' # Load the compiled C library (Ensure the correct path to part3.so)

  # Define the C functions here
  extern 'void* new_table()'
  extern 'void free_table(void*)'
  extern 'int execute_statement(void*, void*)'
end

def execute_statement_wrapper(statement, table)
  Part3.execute_statement(statement, table)
end

# Test the code
table = Part3.new_table

# Insert a row
statement = Fiddle::Pointer.malloc(4 + 32 + 255)  # Allocate memory for the statement
statement[0, 4] = [0].pack('L')                   # Pack the 'id' field (uint32_t)
statement[4, 32] = ["username"].pack('A32')       # Pack the 'username' field (32 characters)
statement[36, 255] = ["user@example.com"].pack('A255')  # Pack the 'email' field (255 characters)

execute_statement_wrapper(statement, table)



# Clean up
Part3.free_table(table)

puts 'Test completed.'
