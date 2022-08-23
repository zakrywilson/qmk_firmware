# zakrywilson's Corne layout

```
```

## Compiling

```sh
make clean
make crkbd:zakrywilson
```

## Flashing

```sh
make crkbd:zakrywilson:flash
```

## Generating Ascii keymap

### Mac

```sh
output_file="ascii_keymap.txt"

rg "\* " --glob keymap.c | cut -c 12- > $output_file
pbcopy < $output_file
```

### Linux

```sh
output_file="ascii_keymap.txt"

rg "\* " --glob keymap.c | cut -c 12- > $output_file
xclip -sel clip $output_file
```

## Generating Json

The resulting Json can be imported into the
[QMK Online Configurer](https://config.qmk.fm/).

```sh
qmk c2json -km zakrywilson -kb crkbd keymap.c | python3 -m json.tool > corne.json
```
