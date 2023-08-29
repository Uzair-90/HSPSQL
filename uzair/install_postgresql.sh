#!/bin/bash

# Check if Homebrew is installed
if ! command -v brew &> /dev/null; then
  echo "Homebrew not found. Installing Homebrew..."
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi

# Install PostgreSQL using Homebrew
echo "Installing PostgreSQL..."
brew install postgresql

# Check installation status
if command -v psql &> /dev/null; then
  echo "PostgreSQL installed successfully!"
else
  echo "Failed to install PostgreSQL."
fi

