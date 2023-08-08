require 'Open3'

RSpec.describe 'BTree Program' do
  it 'inserts and displays values correctly' do
    input_commands = [
      "i\n",
      "5\n",
      "i\n",
      "3\n",
      "p\n",
      "s\n"
    ]
    expected_output = "The size of bucket is 3!\nEnter operation to perform: i for insert, p for display, S to stop: Enter an integer value: Enter operation to perform: i for insert, p for display, S to stop: 3 5 \t\nEnter operation to perform: i for insert, p for display, S to stop: "

    stdout, stderr, status = Open3.capture3('./bplustree', stdin_data: input_commands.join)

    expect(stdout).to eq(expected_output)
    expect(status.success?).to be(true)
  end
end
