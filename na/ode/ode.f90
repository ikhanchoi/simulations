program ode
    implicit none
    
    real :: t, x, h, t_end
    integer :: n, i
    real, external :: f

    ! initial
    t = 0.0         ! initial time t0
    x = 1.0         ! initial condition y(t0) = 1
    h = 0.1         ! time step (step size)
    t_end = 5.0     ! final time
    
    n = int((t_end - t) / h)  ! iteration count
    
    do i = 1, n
       x = x + h * f(t, x)
       t = t + h
    end do
    print *, 'Final result: ', x
end program ode
  
real function f(t, x)
    implicit none
    real, intent(in) :: t, x
    f = -2.0 * x + sin(t)
end function f