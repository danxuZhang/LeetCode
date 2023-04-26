#!/usr/bin/perl

# Usage: perl clean_comments.pl input_file [output_file]

use strict;
use warnings;

my $in_file = shift @ARGV;
my $out_file = shift @ARGV;

if (not defined $in_file) {
    die "Usage: perl clean_comments.pl input_file [output_file]\n";
}

my $in_fh;
if ($in_file eq '-') {
    $in_fh = \*STDIN;
}
else {
    open $in_fh, '<', $in_file or die "Can't open input file: $!";
}

my $out_fh;
if (not defined $out_file or $out_file eq '-') {
    $out_fh = \*STDOUT;
}
else {
    open $out_fh, '>', $out_file or die "Can't open output file: $!";
}

my $inside_class = 0;
while (my $line = <$in_fh>) {
    if ($line =~ /class Solution \{/) {
        $inside_class = 1;
    }
    elsif ($line =~ /\};/) {
        $inside_class = 0;
    }
    if ($inside_class) {
        print $out_fh $line;
    }
    else {
        $line =~ s/\/\*.*?\*\///g; # remove documentation comments
        $line =~ s/\/\/.*//; # remove single-line comments
        print $out_fh $line;
    }
}

close $in_fh;
close $out_fh;
