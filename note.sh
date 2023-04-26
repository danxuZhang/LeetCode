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
md_dir="notes/$md_file"

echo $code_file
echo $md_file
echo $md_dir

mkdir -p notes

if [ ! -e $md_dir ]; then
    touch $md_dir
    echo "# ${code_file%.*}\n" > $md_dir
    echo "Created new Markdown file $md_dir"
fi

echo "## ${msg}\n" >> $md_dir
echo "\`\`\` $lang" >> $md_dir
cat  $code_file >> $md_dir
echo "\`\`\`\n" >> $md_dir

echo "Updated $md_dir"
