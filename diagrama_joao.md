
# 1. DESENHAR UMA REDE
graph LR
    h1[Host h1]
    h2[Host h2]
    h3[Host h3]
    h4[Host h4]
    h5[Host h5]

    s1[Switch s1]
    s2[Switch s2]

    h1 --- s1
    h2 --- s1
    h3 --- s1

    h4 --- s2
    h5 --- s2

    s1 --- s2

# 2. IMPLEMENTAR UMA REDE

Foi configurado a rede com o seguinte código em python:
``` py
#!/usr/bin/env python3

from mininet.net import Mininet
from mininet.cli import CLI
from mininet.log import setLogLevel

def cria_rede():
    net = Mininet(controller=None)  # Sem controlador

    # Adiciona switches
    s1 = net.addSwitch('s1')
    s2 = net.addSwitch('s2')

    # Adiciona hosts
    h1 = net.addHost('h1')
    h2 = net.addHost('h2')
    h3 = net.addHost('h3')
    h4 = net.addHost('h4')
    h5 = net.addHost('h5')

    # Conecta hosts ao switch s1
    net.addLink(h1, s1)
    net.addLink(h2, s1)
    net.addLink(h3, s1)

    # Conecta hosts ao switch s2
    net.addLink(h4, s2)
    net.addLink(h5, s2)

    # Conecta os switches entre si
    net.addLink(s1, s2)

    net.start()

    print("Rede criada! Teste a conectividade com 'pingall'")
    net.pingAll()

    CLI(net)
    net.stop()

if __name__ == '__main__':
    setLogLevel('info')
    cria_rede()

# DEPOIS

# chmod +x minha_rede.py

# sudo python3 minha_rede.py
```


## 2.1 COMO ADICIONAR UM SWITCH
addSwitch s3

## 2.2 COMO ADICIONAR UM HOST
addHost h6

## 2.3 COMO ADICIONAR UM CONTROLADOR
addController c1
