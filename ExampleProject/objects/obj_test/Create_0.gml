var hwnd = window_handle()

//Note: You can use R: 0 G: 0 B: 0, but it will break minimize, close, and maximize buttons
make_color_transparent(string(hwnd), 50, 50, 50)