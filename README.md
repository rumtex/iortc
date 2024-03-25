# I/O Realtime Core
Linux-platform ANSI C systemd-service:
- provider for servo, sensors, etc.
- remote-controllable
- presentation (eg. multimedia)

## build
```sh
mkdir build
cd build
cmake ..
make
```
CMake configuration build "-D" options:
* DEBUG

## schematic

```mermaid
graph LR
    A(Athmos) -- greetings --> B(Beriya)
    B -- greetings --> A
    B --> D{vaporarium<br/>#129767;#128038;#8205;#128293;}
    A --> D
    A -- tasking --> C((Athmos<br/>hardware<br/>network))
    E((Beriya's<br/>hardware<br/>network)) -- assist --> C
```

```mermaid
sequenceDiagram
    title component communication bus
    box purple remote sources's
    participant dynamic gift (WWW)
    participant huge storage
    participant ext. computing
    participant union
    end
    actor User
    box API's
    participant PC (web cli)
    participant voice
    participant reminder
    end
    box blue models
    participant energy
    participant computing
    participant workflow
    participant research
    participant actual
    participant communication
    end
    box red storage
    participant tasks
    participant BOT %%Best of the ..
    end
    loop runtime (with different period)
        workflow-->research: check sources
        workflow-->energy: update model
        workflow-->tasks: reprioritize
    Note left of User: Bob thinks a long.
        workflow-->dynamic gift (WWW): *TASK* research markets, news, popular and favorite pulic sources
        workflow-->reminder: *TASK* process and complitions reporting
        workflow-->ext. computing: *TASK* using
        workflow-->huge storage: *TASK* using
        workflow-->computing: *TASK* using
        workflow-->communications: *TASK* using, e.g. running union API
        workflow-->actual: *TASK* using sensors, drivers for excavation, examination etc.
    end
```

## NOTES
blacklist user-work work must be, at first, with languistic model (source blacklisting after)

## STATE
active development

## LICENSE
Free Non-Commercial usage

## Contact
Глушков Александр @rumtex mailto:rummtex@gmail.com
