program mat_prod_blas
  implicit none

  integer(4) :: count1, count2, count_rate, count_max
  integer(4), parameter :: l=1000, m=2000, n=3000
  real(8) :: a(1:l, 1:m), b(1:m, 1:n), c(1:l, 1:n)

  call random_number(a)
  call random_number(b)

  call system_clock(count1)
  call dgemm('n', 'n', l, n, m, 1.0d0, a, l, &
  &          b, m, 0.0d0, c, l)
  call system_clock(count2, count_rate, count_max)

  write(*, *) ' cpu time = ', (count2-count1)/dble(count_rate), ' s'

end program mat_prod_blas