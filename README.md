
<h1 align="center"> Awesome </h1>

<p align="center">
<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?lines=Welcome+to+the+Awesome+Project!;It's+Helpful.+Nifty.+Zippy.+Use+it." alt="Typing SVG" /></a>
</p>

<p align="center">
  <br>
  My name is Enzo, I'm a french postbac student 🏫 in my second year, specializing in physics and engineering science ! 👨‍🔬 I also have a great passion for programming so here is my main project: Awesome 😄
  <br> <br>
  This project <b> started </b> thanks to a great passion for ECS. I love this way of thinking  beyond deep object-oriented programming. I want Awesome to be <b>modern</b>, <b>well thought out</b> and <b>easy to use</b>. In this regard I decided to use XMake project manager. You can learn about it <a href="https://xmake.io/#/"> here</a>. Don't panic, XMake allows to generate CMake files: it can be used in every IDE, Code Editor that allows to manage CMake projects.
</p>

<h2 align="center"> Usage </h2>

The main aspect I want people to respect about Awesome is its **easy-to-use** structure.

<h3 align="center"> XMake </h3>
First of all, you need to install XMake: please refer to <a href="https://xmake.io/mirror/guide/installation.html">this</a> page.

Let's suppose you have created a folder `my-project` with a `main.cpp` file in it. One way to produce an executable with XMake is :

```C
add_rules ("mode.debug", "mode.release")

target ("my-project")
    set_kind ("binary")
    set_languages ("cxxlatest", "clatest")

    add_files ("main.cpp")
```
Now if you want to use **Awesome**, you have to clone the repository into a folder (for example, `third_party`). The XMake input should be
```C
add_rules ("mode.debug", "mode.release")

target ("my-project")
    set_kind ("binary")
    set_languages ("cxxlatest", "clatest")

    add_files ("main.cpp")

    includes("third_party/awesome/xmake.lua")
    add_deps ("awesome")
```
That's all!
<h3 align="center"> CMake </h3>

Once XMake has been installed and your project has been configured (following the XMake part) you may need a **CMakeLists.txt**. Indeed, IDEs like CLion used to work with this. It's quite easy to generate your CMakeLists.txt: go to `my-project` directory, open a prompt next to the `xmake.lua` file and write
```C
xmake project -k cmakelists
```
Once again, that's all! XMake is very powerful.

<h2 align="center"> Documentation </h2>
