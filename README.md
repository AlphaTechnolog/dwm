# My Custom Dwm Build

This is my custom dwm build which not uses dwmblocks or something similar for bar, i created a custom script approaching the status2d patch :3

![demonstration](./misc/demonstration.png)

[Enjoy notes](#enjoy)

## Requirements

- JetBrainsMono Nerd Font (general font)
- Iosevka Nerd Font (for dashboard with eww)
- eww (for dashboard)
- rofi (for select apps)
- dunst (for notifications)
- picom (compositor)
- light (for get brightness)
- exa (ls replacement)
- bat (cat replacement)
- alsa-utils (for amixer)
- wireless\_tools (iwgetid)

## About this

### Dwm patches

- underlinetag 
- status2d
- restartsig
- rotatestack
- fullgaps
- bar-height
- fixborders
- noborder
- notitle
- pertag

### St

The st config is based in [siduck's st config](https://github.com/siduck/st)

## Installation

> First make sure u have all the [requirements](#requirements) installed on ur system

1. Clone the repo:

```sh
git clone https://github.com/AlphaTechnolog/dwm.git dwm
cd dwm
```

2. Then, copy the configs:

```sh
cp -r ./config/* ~/.config
cp -r ./bin/* ~/.local/bin
cp -r ./home/* ~/
```

3. Create the launcher

If u're using a login manager like sddm or lightdm u can copy the .desktop to `/usr/share/xsessions` and replace in the file
`/usr/share/xsessions/dwm.desktop` the name `gabriel` to ur username.

```sh
sudo cp -r ./launchers/dwm.desktop /usr/share/xsessions
sudo nvim /usr/share/xsessions/dwm.desktop # and change gabriel to ur username in the file
```

If u're using startx, u can copy the file xinitrc, that contains an example orders to execute dwm, feel tree to customize it:

```sh
cp -r ./launchers/xinitrc ~/.xinitrc
```

Then startx:

```sh
startx
```

4. Compile dwm

```sh
cd ~/.config/dwm/src
test -f config.h && rm config.h
sudo make clean install
```

5. Compile st

```sh
cd ~/.config/st
test -f config.h && rm config.h
sudo make clean install
```

## Enjoy!

I hope u like this :3

if yes, please give me a star
