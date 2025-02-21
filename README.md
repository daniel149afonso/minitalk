server.c:
//ft_print_binary(bit_acc); //mettre apres bit_count++

//ft_printf("Character received: %c \n", bit_acc);// mettre en premier dans le if

client.c:
//ft_printf("le char: %c\n", msg[i]); mettre apres le c = msg[i]


static int g_ack = 0;               // ✅ Pour confirmer chaque bit (SIGUSR1)
static int g_message_confirmed = 0;  // ✅ Pour confirmer la réception complète (SIGUSR2)

void	handle_ack(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("ACK reçu: SIGUSR1 (bit confirmé)\n");
	}
	else if (signal == SIGUSR2)
	{
		g_message_confirmed = 1;  // ✅ SIGUSR2 reçu, le message est complet
	}
	else
	{
		ft_printf("⚠️ Signal inattendu reçu : %d\n", signal);
	}
}

void	ft_send_signal(int pid, char c, int *bit)
{
	int signal;

	if (((c >> *bit) & 1) == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;

	if (kill(pid, signal) == -1)
	{
		ft_printf("Error: Failed to send signal to server\n");
		exit(EXIT_FAILURE);
	}

	// ✅ Attendre le ACK (SIGUSR1) avant d'envoyer le prochain bit
	while (!g_ack)
		pause();
}

void	ft_send_message(int pid, char *msg)
{
	int		bit;
	int		i;
	char	c;
	int		len;

	i = 0;
	len = ft_strlen_v2(msg) + 1;
	while (i < len)
	{
		bit = 7;
		c = msg[i];
		while (bit >= 0)
		{
			g_ack = 0;  // ✅ Reset du ACK avant chaque bit
			ft_send_signal(pid, c, &bit);
			bit--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error: The correct format is %s <PID> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);

	// ✅ Réception des signaux avant l'envoi du message
	signal(SIGUSR1, handle_ack);
	signal(SIGUSR2, handle_ack);

	ft_send_message(pid, argv[2]);

	// ✅ Attendre la confirmation du message complet
	while (!g_message_confirmed)
	{
		ft_printf("🕐 Attente de SIGUSR2...\n");
		pause();
	}

	ft_printf("✅ Message delivered!\n");
	return (0);
}
