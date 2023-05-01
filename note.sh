#!/bin/sh

if [ "$#" -ne 2 ]; then
  echo "Usage: note.sh [Problem Number] [A short message about the solution]"
  exit 1
fi

n=$1
msg=$2
lang="cpp"
code_file=$(basename $(find . -type f -maxdepth 1 -name "1.*.$lang"))
md_file=$(echo $code_file | sed "s/\.$lang$/.md/")
md_path="notes/$md_file"

echo $code_file
echo $md_file
echo $md_path

mkdir -p notes

if [ ! -e $md_path ]; then
    touch $md_path
    echo "# ${code_file%.*}\n" > $md_path
    echo "Created new Markdown file $md_path"
fi

echo "## ${msg}\n" >> $md_path
echo "\`\`\` $lang" >> $md_path
cat  $code_file >> $md_path
echo "\`\`\`\n" >> $md_path
echo "" >> $md_path

echo "Updated $md_path"
