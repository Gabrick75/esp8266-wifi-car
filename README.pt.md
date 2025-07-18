Este repositório está disponível em: 🇧🇷 [Português](README.pt.md)  
This repository is available in: 🇺🇸 [English](README.md)

# 🚗 Carrinho Controlado por Wi-Fi com ESP8266 (Wemos D1 R1)

Este projeto utiliza um **ESP8266 (Wemos D1 R1)** para controlar um carrinho via Wi-Fi. O controle é feito diretamente pelo navegador ao acessar o endereço IP do ESP. Com uma interface simples, o usuário pode controlar as direções do carrinho, ajustar a velocidade dos motores e realizar um teste.

## 🔧 Funcionalidades
- Controle de direção: frente, ré, esquerda e direita.
- Controle de velocidade ajustável.
- Botão de teste para verificar o funcionamento dos motores.
- Interface web acessível pelo IP do ESP8266.

## 🧰 Requisitos
- Placa Wemos D1 R1 (ESP8266)  
- Módulo controlador de motores (ex: L298N)  
- Dois motores DC  
- Fonte de alimentação (bateria ou fonte externa)  
- Fios e protoboard (ou montagem soldada)  

## 🌐 Como Usar
- Altere o **SSID** e a **senha da rede Wi-Fi** no código.
- Envie o código para o Wemos D1 R1 usando a Arduino IDE.
- Conecte os motores e o módulo controlador ao Wemos D1 R1.
- Alimente o ESP8266 e verifique o endereço IP atribuído (pelo Monitor Serial).
- Acesse esse IP em um navegador, num dispositivo conectado à mesma rede.
- Use a interface para controlar o carrinho em tempo real.

## 💡 Observações
- O carrinho deve estar conectado à **mesma rede Wi-Fi** que o dispositivo de controle (como celular ou PC).
- O código pode ser facilmente modificado para adicionar sensores ou controle por joystick virtual.

## 📸 Imagens

### Interface Web no Navegador
![Interface web](image/interface_web.png)

## 📜 Licença

Este projeto está licenciado sob a **Creative Commons Atribuição-NãoComercial 4.0 Internacional (CC BY-NC 4.0)**.  
> Para uso comercial, entre em contato comigo para obter uma licença.

Você tem permissão para:
- Usar, copiar e modificar o projeto para **fins pessoais e não comerciais**.
- Compartilhar, desde que dê os devidos créditos.

Você **não pode**:
- Usar este trabalho para fins comerciais (incluindo revenda ou integração em produtos ou serviços pagos).

Mais informações: [https://creativecommons.org/licenses/by-nc/4.0/deed.pt](https://creativecommons.org/licenses/by-nc/4.0/deed.pt)

[![Licença: CC BY-NC 4.0](https://licensebuttons.net/l/by-nc/4.0/88x31.png)](https://creativecommons.org/licenses/by-nc/4.0/)
