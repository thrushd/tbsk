# tbskb: Trackball Split Keyboard

![tbskb](https://dylanthrush.com/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F622b27fe-97e4-4e11-96f6-2518c6bf0f85%2FAR_05694.jpg?table=block&id=3f116c58-3201-41d0-83f5-e956424e39d9&spaceId=0300d8ef-5be1-45c4-9977-2409a805718d&width=2000&userId=&cache=v2)

This is the repository for the firmware used in the [tbsk](https://dylanthrush.com/TBSK-a4ad0d327c9d4cd4b084e54ac9fb8fc8). This repo is here as a reference for anyone attempting a similar project. I will not be making any additional contributions in the future, but I hope this helps as is.

# How to use this firmware
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Once you have the above steps working you can download this repo and place it in `qmk_firmware\keyboards`.

Next you can make and upload to the designated half using:

    `make tbskb:default:dfu-split-right`
    `make tbskb:default:dfu-split-left`
