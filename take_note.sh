#!/bin/sh

if [ "$#" -ne 2 ]; then
  echo "Usage: note.sh [Problem Number] [A short message about the solution]"
  exit 1
fi

n=$1
msg=$2
lang="cpp"
output_dir="notes/"
code_file=$(basename $(find . -type f -maxdepth 1 -name "$n.*.$lang"))
md_file=$(echo $code_file | sed "s/\.$lang$/.md/")
md_path="$output_dir/$md_file"

echo "Code file: $code_file"
echo "Markdown notes file: $md_file ($md_path)"

mkdir -p $output_dir

if [ ! -e $md_path ]; then
    touch $md_path
    echo "# ${code_file%.*}" > $md_path
    echo "" >> $md_path
    echo "Created new Markdown file $md_path"
fi

echo "## ${msg}" >> $md_path
echo "" >> $md_path
echo "\`\`\` $lang" >> $md_path
cat  $code_file >> $md_path
echo "\`\`\`" >> $md_path
echo "" >> $md_path

echo "Updated $md_path"
