# This Directory is used for set up develop environment for FAST_INTR_CPU.

> Chisel is not a language, it's a library for `Scala`. Scala is a high level language which is very similar to `Java`. Scala has to run in JVM.

So in order to use Chisel to write code for Digital Circuits, we have to install JDK and sbt.
1. JDK is short for Java Development Kits, as described before Scala has to run in JVM.
    ```bash
    sudo apt install openjdk-11-jdk
    ```
    
2. Install sbt, sbt is a build tool for Scala. SBT can be used to
    - Compile Scala projects
    - Download libraries for Scala, for example sbt can download Chisel jars automatically.

    We can't just use `apt install sbt` to install sbt, because Ubuntu's official repository doesn't have sbt. Use the following commands to install sbt on Ubuntu. [The official installation guide for SBT](https://www.scala-sbt.org/1.x/docs/Installing-sbt-on-Linux.html).
    ```bash
    sudo apt-get update
    sudo apt-get install apt-transport-https curl gnupg -yqq
    echo "deb https://repo.scala-sbt.org/scalasbt/debian all main" | sudo tee /etc/apt/sources.list.d/sbt.list
    echo "deb https://repo.scala-sbt.org/scalasbt/debian /" | sudo tee /etc/apt/sources.list.d/sbt_old.list
    curl -sL "https://keyserver.ubuntu.com/pks/lookup?op=get&search=0x2EE0EA64E40A89B84B2DF73499E82A75642AC823" | sudo -H gpg --no-default-keyring --keyring gnupg-ring:/etc/apt/trusted.gpg.d/scalasbt-release.gpg --import
    sudo chmod 644 /etc/apt/trusted.gpg.d/scalasbt-release.gpg
    sudo apt-get update
    sudo apt-get install sbt
    ```
    
3. Check if your enviroment is OK
    ```bash
    javac --version # should output some info about java
    java --version  # should output some info about javac
    sbt             # should enter sbt shell, ctrl+C to quit
    ```
    We can also run a chisel-example to check Scala works well.
    ```bash
    git clone https://github.com/schoeberl/chisel-examples.git
    cd chisel-examples/hello-world/
    ```
    hello-world is a self contained minimal project for a blinking LED in an FPGA. You can find the chisel codes under `src` folder.
    Use the following code to do a Chisel Test, it should output blinking in terminal.
    ```bash
    sbt test
    ```
    
4. Install Mill, Mill is another tool for building chisel projects like sbt

    ```bash
    sudo sh -c "curl -L https://github.com/com-lihaoyi/mill/releases/download/0.10.8/0.10.8 > /usr/local/bin/mill && chmod +x /usr/local/bin/mill"
    
    mill
    ```
# Acknowledgements
1. [The chisel-examples](https://github.com/schoeberl/chisel-examples) is provided by schoeberl, this repository is a collection of code examples for Chisel. He  also provides a Chisel guide book in [chisel-book](https://github.com/schoeberl/chisel-book).