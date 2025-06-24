# .latexmkrc

# move all output to ./build/
$out_dir = 'build';
$aux_dir = 'build';

# build with pdflatex
$pdflatex = 'pdflatex -interaction=nonstopmode -synctex=1 %O %S';

# keep pdf in the main directory
$copy_rules = 0;
