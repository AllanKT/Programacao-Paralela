# ChatBot - Rasa
### Comandos

- rasa train
Treina o bot (necessário executar após cada mudança ou na primeira vez que estiver rodando o bot)

- rasa run --endpoints endpoints.yml 
Sobe o core do bot na porta 5005

- rasa run actions
Sobe o servidor python que executa as ações customizadas do bot (o core do bot precisa que o server esteja rodando também)

### Requests

O bot pode ser acessado pela rota: host:5005/webhooks/rest/webhook com a seguinte estrutura:

```python
{
	"sender": "id_da_sessao",
	"message": "mensagem_pro_bot"
}
```

### Responses
Todas as respostas do bot seguem o padrão:
```python
    {
        "message": "Resposta do bot",
        "status": 0 | 1 # 0 Caso seja a última mensagem, 1 caso contrário
        "action": "ação a ser executada"
        "contents": {
            "destiny": "nome_da_materia ou coordenacao",
            "content": "corpo do email"
        }
    }
```
Obs: Os requests com status 1 tão retornando com uma \ no corpo do request, talvez seja necessário dar um replace quando a API receber esses valores
