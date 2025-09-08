# Philosophers

Todo
- Print le temps.
http://manpagesfr.free.fr/man/man2/gettimeofday.2.html
- Faire partir les philos pairs en premier, puis inpairs.
-- modulo % i -> philo part.
Dans l'idée :
while (!is_dead)
{
  printf("%d %d is eating", custom_gettimeofday(), philo.id);
  printf("%d is sleeping", philo.id);
  printf("%d is thinkng", philo.id);
}
usleep de time_to_sleep.
Inclure un monitor pour gérer la valeur de is_alive (si gettimeofday - last_meal > time_to_die).
