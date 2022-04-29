# zakrywilson's Kyria layout

## Compiling

```sh
qmk compile -kb kyria -km zakrywilson
```

## Flashing

```sh
qmk flash -kb kyria -km zakrywilson
```

## Output to JSON

```sh
km="zakrywilson"
kb="kyria"
tmp="keymap.tmp"
input_file="keymap.c"
output_file="$kb".json

qmk c2json -km $km -kb $kb $input_file | sed 's/kyria/kyria\/rev1/g' | python -m json.tool > $output_file
```

## Output to Ascii

```sh
input_file="keymap.c"
output_file="ascii_keymap.txt"

rg "\* " --glob $input_file | cut -c 12- > $output_file
xclip -sel clip $output_file
```
