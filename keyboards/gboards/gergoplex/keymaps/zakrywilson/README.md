# zakrywilson's Gergoplex layout

## Compiling

```sh
qmk compile -kb gboards/gergoplex -km zakrywilson
```

## Flashing

```sh
qmk flash -kb gboards/gergoplex -km zakrywilson
```

## Output to Ascii

```sh
input_file="keymap.c"
output_file="ascii_keymap.txt"

rg "\* " --glob $input_file | cut -c 12- > $output_file
xclip -sel clip $output_file
```
