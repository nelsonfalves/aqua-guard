# Aqua Guard: Sensor de Vazamento de Água com ESP32 e MQTT

## Descrição do Projeto

O Aqua Guard é um sistema inteligente de detecção de vazamentos de água utilizando a plataforma ESP32. O sistema monitora continuamente um sensor de água e, ao detectar um vazamento, aciona um alarme sonoro (buzzer) e envia uma notificação via protocolo MQTT para um tópico específico, permitindo o monitoramento remoto do evento.

## Funcionamento e Uso

1. O ESP32 lê periodicamente o valor do sensor de água.
2. Se um vazamento for detectado (valor acima do limite configurado), o buzzer é acionado e uma mensagem de alerta é publicada no tópico MQTT.
3. O sistema pode ser facilmente reproduzido conectando o hardware conforme descrito abaixo e carregando o código fornecido.

## Software Desenvolvido

O código-fonte está disponível no arquivo `aplicando4.c`. Ele utiliza as bibliotecas WiFi e PubSubClient para conexão à rede e comunicação MQTT. O código está documentado com comentários explicativos para facilitar a compreensão e modificação.

## Hardware Utilizado

-    **Plataforma de desenvolvimento:** ESP32 DevKit
-    **Sensor:** Sensor de nível de água (analógico, conectado ao pino 34) - T1592
-    **Atuador:** Buzzer Passivo Piezoelétrico de Alta Potência - AT3040
     (conectado ao pino 16)
-    **Alimentação:** 5V via USB ou fonte externa
-    **Protoboard e jumpers** para montagem dos circuitos

## Documentação das Interfaces, Protocolos e Módulos de Comunicação

-    **Interface Sensor:** O sensor de água é lido via entrada analógica (ADC) do ESP32.
-    **Atuador:** O buzzer é acionado via saída digital.
-    **Comunicação WiFi:** O ESP32 conecta-se a uma rede WiFi para acesso à internet.
-    **Protocolo MQTT:** Utiliza o broker público HiveMQ (`broker.hivemq.com`) na porta 1883. O tópico utilizado é `aqua/guard`. Mensagens de alerta são publicadas sempre que um vazamento é detectado.
-    **Protocolo TCP/IP:** A comunicação com o broker MQTT ocorre sobre TCP/IP.

## Como Reproduzir

1. Monte o circuito conforme a descrição de hardware.
2. Configure o WiFi e, se necessário, altere o tópico MQTT no código.
3. Faça upload do código para o ESP32.
4. Monitore o tópico MQTT para receber alertas de vazamento.
