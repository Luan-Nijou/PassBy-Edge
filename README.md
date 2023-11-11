<p align="center" >
 <img width=30% height= 30% src="https://github.com/Luan-Nijou/PassBy-Edge/assets/126830016/03bc77d0-0f2f-4920-873d-34258c75ff6b"/>
</p>
<p align="center">
 
  <img src="http://img.shields.io/static/v1?label=License&message=MIT&color=green&style=for-the-badge"/>
  <img src="http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=RED&style=for-the-badge"/>
 
</p>



### Tópicos 

:small_blue_diamond: [Acesso ao projeto](#-acesso-ao-projeto)

:small_blue_diamond: [Descrição do projeto](#-descrição-do-projeto)

:small_blue_diamond: [Layout básico de Arquitetura](#-layout-básico-de-arquitetura)

:small_blue_diamond: [Descrição da Arquitetura](#-descrição-da-arquitetura)

:small_blue_diamond: [Descrição do funcionamento](#-descrição-do-funcionamento)  

:small_blue_diamond: [Layout básico da Simulação](#-layout-básico-da-simulação)

:small_blue_diamond: [Descrição da Simulação](#-descrição-da-simulação)

:small_blue_diamond: [Linguagem Usada](#-linguagem-usada)

:small_blue_diamond: [Desenvolvedores](#-desenvolvedores)

:small_blue_diamond: [Licença](#-licença)



## 📁 Acesso ao projeto

 [Acesso do código fonte da simulação.](https://github.com/Luan-Nijou/PassBy-Edge/blob/main/Code.ino)

## 📝 Descrição do projeto 

<p align="justify">
O PassBy um projeto pioneiro de gestão de estacionamentos,fundamentado na tecnologia de Comunicação de Campo Próximo (NFC). Este empreendimento destina-se a enfrentar de maneira abrangente as crescentes inquietações
relacionadas à sustentabilidade e eficiência nas configurações urbanas. Além de modernizar os sistemas tradicionais de estacionamento, nossa abordagem visa catalisar a 
conscientização sobre a importância de priorizar a preservação ambiental em todas as esferas da sociedade 
</p> 

## 🧰 Layout básico de Arquitetura 


![PassBy arquitetura](https://github.com/Luan-Nijou/PassBy-Edge/assets/126830016/42ee9ff0-d52b-4928-8a28-a1a14114a040)



## 📋 Descrição da Arquitetura 

**Instância 1 - Dispositivos IoT e Interação NFC-RFID:**
<p align="justify">
 Nesta primeira instância, o projeto envolve a conexão de todos os ambientes à internet. Os dispositivos IoT desempenham um papel fundamental na troca de informações. Um dispositivo móvel equipado com um chip NFC é usado para estabelecer comunicação com um totem. Este totem possui uma placa ESP32 e um sensor RFID para capturar as informações trocadas e enviá-las para o banco de dados central. Essa interação permite que informações essenciais sejam compartilhadas de forma eficiente e segura.
 <p/>
  
**Instância 2 - Aplicativo de Gerenciamento:**
<p align="justify">
 Na segunda instância, o aplicativo é o ponto de controle central. Ele está conectado a informações estáticas, como os IDs dos carros, e também oferece monitoramento em tempo real da localização dos carros. Além disso, o aplicativo é integrado a um sistema de pagamento, fornecendo aos usuários a conveniência de uma carteira virtual para realizar transações de pagamento. Esta parte do projeto torna a interação dos usuários com o sistema mais intuitiva e funcional.
 <p/>
  
 **Instância 3 - Ambiente de Servidores e Segurança:**
<p align="justify">
 A terceira instância concentra-se no ambiente dos servidores, que é o cérebro do sistema. Aqui, todos os dados são processados, armazenados e gerenciados de maneira segura. Isso inclui o registro de transações de pagamento e a manutenção de registros cruciais. A segurança é uma prioridade nesta instância, garantindo que todas as operações sejam protegidas e os dados permaneçam confidenciais.
<p/>
<p align="justify">
Essas melhorias nas descrições destacam a importância de cada instância do projeto e como elas se conectam para criar um sistema abrangente de gerenciamento de informações, monitoramento e pagamento.
<p/>

## 📋 Descrição do funcionamento

**Acesso ao Sistema:**
<p align="justify">
Para acessar o sistema completo, é necessário ter o aplicativo instalado em seu dispositivo móvel e possuir um chip NFC associado ao dispositivo.
 <p/>
  
**Configuração do Aplicativo:**
<p align="justify">
Antes de usar o sistema, é necessário configurar o aplicativo. Isso inclui realizar um cadastro no aplicativo, onde você fornecerá suas informações pessoais e receberá uma identificação de registro exclusiva, gerada aleatoriamente.
 <p/>

  **Registro Automático no Totem:**
<p align="justify">
Uma vez que o aplicativo esteja configurado e você tenha sua identificação de registro, basta aproximar seu celular do totem local. O totem está equipado com tecnologia NFC que permite a troca de informações de forma segura e instantânea. Quando você passa o celular no totem, ele automaticamente registra sua presença no servidor do estacionamento.
 <p/>
  
**Monitoramento e Cálculo de Pagamento:**
<p align="justify">
Após o registro no servidor, o aplicativo exibirá em tempo real o período de tempo que você está ocupando o espaço de estacionamento. Além disso, o sistema calcula automaticamente o valor a ser pago com base no tempo que você passou no local, conforme as tarifas estabelecidas.
Essas descrições refinadas destacam a simplicidade e a eficiência do processo, desde a configuração inicial até o uso prático do sistema para registro de presença e cálculo de pagamento em tempo real.
 <p/>
  
## 🧰 Layout básico da Simulação

![LayoutSimulação](https://github.com/Luan-Nijou/PassBy-Edge/assets/126830016/e6ab3583-d07f-4397-bf46-fd9e6c17b635)

## 📋 Descrição da Simulação

<p align="justify">
Com o sistema de internet funcionando do ESP32, transmitirá informações para o site, a plataforma terá a função de exibir em 3 display, 1º se foi confirmado o ID(Cadastrado para ID condizente), 2º mostrando o ID, e o 3º se o ID pode passar(CONFIRMADO para acesso permitido)
<p/>
 
![Tago3](https://github.com/Luan-Nijou/PassBy-Edge/assets/126830016/ea4461c4-96b5-4853-9ccf-2b3567f3b47d)

## Replicar 

<p align="justify">
Para replicar ou/e modificar do seu modo:

 1. Possuir em seu dispositivo o acesso ao projeto da [Wokwi](https://wokwi.com/projects/381019449164549121) e uma conta na [tago.io](https://tago.io),e [aqui um video](https://www.youtube.com/watch?v=leKi6Tt3DXI) para enteder o basico da tago.
 2. Possuir o hardware no Wokwi, que seráa apenas um ESP32.
 3. Depois, faça as configurações principais do código, como: Colocar o nome e a senha corretamente(ou apenas testar com a própria "internet" do projeto, que é uma internet teste da Wokwi), e o token do device que foi criado na tago.
 4. E assim faça seus testes!!
<p/>

## 💻 Linguagem Usada

<img src="https://www.alura.com.br/artigos/assets/formacao-linguagem-c-plus-plus/img-01.png" width=50/>


## 💻 Desenvolvedores 


| [<img src="https://i.imgur.com/ZIv3QYz.jpg" width=150 height= 150><br><sub>Luan Nijou</sub>](https://github.com/Luan-Nijou) | [<img src="https://i.imgur.com/p8nq4Xu.jpg" width=150 height= 150><br><sub>Pedro Henrique Alves Guariente</sub>](https://github.com/predowss) | [<img src="https://i.imgur.com/qiQoCcq.jpg" width=150 height= 150><br><sub>David de Medeiros Pacheco Junior</sub>](https://github.com/daviddpacheco) | [<img src="https://i.imgur.com/noeh6xz.jpg" width=150 height= 150><br><sub>Kaique Maia Reis Silva</sub>](https://github.com/kaiquemaiaa) | [<img src="" width=150 height= 150><br><sub>Orlando Akio Morii Cardoso</sub>](https://github.com/AkioMorii) |
| :---: | :---: | :---: | :---: | :---: |


## Licença 

The [MIT License]() (MIT)

Copyright :copyright: 2023 - PassBy
