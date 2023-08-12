describe 'database' do
  before do
    `rm -rf mydb.db`
  end

  def run_script(commands)
    raw_output = nil
    IO.popen("./part9 mydb.db", "r+") do |pipe|
      commands.each do |command|
        pipe.puts command
      end

      pipe.close_write

      raw_output = pipe.gets(nil)
    end
    raw_output.split("\n")
  end

  it 'keeps data after closing connection' do
    result1 = run_script([
      "insert 1 user1 person1@example.com",
      ".exit",
    ])
    expect(result1).to match_array([
      "db > Executed.",
      "db > ",
    ])

    result2 = run_script([
      "select",
      ".exit",
    ])
    expect(result2).to match_array([
      "db > (1, user1, person1@example.com)",
      "Executed.",
      "db > ",
    ])
  end

  it 'prints error message when table is full' do
    script = (1..1401).map do |i|
      "insert #{i} user#{i} person#{i}@example.com"
    end
    script << ".exit"

    result = run_script(script)
    expect(result[-2]).to eq("db > Error: Table full.")
  end
  it 'allows printing out the structure of a one-node btree' do
      script = [3, 1, 2].map { |i| "insert #{i} user#{i} person#{i}@example.com" }
      script << ".btree"
      script << ".exit"
      result = run_script(script)
  
      expect(result).to match_array([
        "db > Executed.",
        "db > Executed.",
        "db > Executed.",
        "db > Tree:",
        "leaf (size 3)",
        "  - 0 : 3",
        "  - 1 : 1",
        "  - 2 : 2",
        "db > "
      ])
    end
  
  it 'prints constants' do
      script = [
        ".constants",
        ".exit",
      ]
      result = run_script(script)
  
      expect(result).to match_array([
        "db > Constants:",
        "ROW_SIZE: 291",
        "COMMON_NODE_HEADER_SIZE: 6",
        "LEAF_NODE_HEADER_SIZE: 10",
        "LEAF_NODE_CELL_SIZE: 295",
        "LEAF_NODE_SPACE_FOR_CELLS: 4086",
        "LEAF_NODE_MAX_CELLS: 13",
        "db > ",
      ])
    end
  
  
end
