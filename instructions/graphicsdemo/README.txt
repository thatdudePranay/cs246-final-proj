Compile the files in this directory as follows:

    g++20h iostream cstdlib string
    g++20 -c window.cc
    g++20 -c window-impl.cc
    g++20 -c graphicsdemo.cc
    g++20 *.o -lX11 -o demo

Then run: ./demo

Note: "-lX11" is "dash little-ell big-ex one one". It won't link in the X11 library code
without this!

[Alternatively, use the "tools/compile" script with the arguments: order.txt demo -lX11]

You should see a window with a blue bar and the string "Hello!" if you've successfully
set the X11 server to run and display. The window will disappear and the program will
end once you put the focus back in your terminal window and enter a character i.e. the
program is waiting for input. Once the window's destructor executes, the window will
disappear.
