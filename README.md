# Bazel Example
 
An example in C using [Bazel](https://www.bazel.build/) to make the environment.

## About This Project

This project uses tennis fans watching [Wimbledon](https://www.atptour.com/en/tournaments/wimbledon/540/overview) 2019 as anology for understanding how to use Bazel.

The following features of Bazel are covered:

- Structuring a Bazel project with `WORKSPACE` and `BUILD` files
- Building libraries.
- Loading local libraries within the same workspace and libraries from another local workspace.
- Visualizing the dependency graph

The following features of Bazel are NOT covered:

- [Creating and loading a Macro](https://docs.bazel.build/versions/master/skylark/tutorial-creating-a-macro.html)
- [Bazel extensions](https://docs.bazel.build/versions/master/skylark/concepts.html#extension-overview)
- [Other methods to load external dependencies](https://docs.bazel.build/versions/master/external.html)


#### Project Structure

The fans in a tennis fan club are watching Wimbledon 2019 Men's Singles: Federer vs Nadal on television. Federer's fans are cheering for Federer, of course, and booing Nadal, without doubt. Nadal's fans are doing the same thing back.

In this project, the main program to build and run is `tennisfanclub/main/wimbledon_2019.c`. The program depends on some fan behaviors defined in `tennisfanclub/tennisfanclub/fan/behavior.c`, some television control methods defined in `television/television/control.c`, and the television channels defined in `television/television/channel/list.h`.

Here is the overall structure:

```
- Workspace: television
    ○ Package: television
        § Package: control
            □ control.c, control.h
                ® watch
        § Package: channel
            □ list.h
- Workspace: tennisfanclub
    ○ Package: tennisfanclub
        § Package: fan
            □ behavior.c, behavior.h
                ® cheer_for
                ® boo_for
    ○ Package: main
        § wimbledon_2019.c
            □ watch(tennis)
            □ cheer_for(federer, federer)
            □ boo_for(federer, nadal)
            □ cheer_for(nadal, nadal)
            □ boo_for(nadal, federer)
```

## Usage

1. [Install Bazel](https://docs.bazel.build/versions/master/install.html).
2. Clone this repository. `cd` into `tennis_example/tennisfanclub`.
3. Run `bazel run //main:wimbledon_2019`.

Output:

```
Channel 1: Wimbledon 2019 Semi-Final, Men's Singles: Roger Federer vs Rafael Nadal!
Federer's fans cheer for Federer!
Federer's fans boo for Nadal!
Nadal's fans cheer for Nadal!
Nadal's fans boo for Federer!
``` 

To clean the project, run `bazel clean`.

## Visualization

Run `bazel query --nohost_deps --noimplicit_deps 'deps(//main:wimbledon_2019)' --output graph`, and dump the output into tools such as [GraphViz](http://www.webgraphviz.com/).
