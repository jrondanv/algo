// Entrada: nh, nm, número de vértices nos lados esquerdo e direito 
// dist[h][m], custo das arestas 
// Saída: h[], par do vértice i do lado esquerdo 

int augment(int curman) { 
  int i,j; 
  vm[curman] = mark; 
  for (int i = 0; i < nh; i++) { 
    if (newdist[curman][i] == 0 && m[i] == -1) { 
      m[i] = curman; 
      h[curman] = i; 
      return 1; 
    } 
  } 
  for (int i = 0; i < nh; i++) { 
    if (newdist[curman][i] == 0 && vh[i] != mark) { 
      vh[i] = mark; 
      if (augment(m[i])) { h[curman] = i; m[i] = curman; return 1; } 
    } 
  } 
  return 0; 
} 

int hungarian() { 
  for (int i = 0; i < nm; i++) 
    for (int j = 0; j < nh; j++) 
      newdist[i][j]=dist[i][j]; 
  mark = 0; 
  for (int i =0 ; i < nm; i++) { 
    vm[i] = 0; 
    h[i] = -1; 
  } 
  for (int i =0 ; i < nh; i++) { 
    vh[i] =0; 
    m[i] = -1; 
  } 
  for (int k = 0; k < nm; k++) { 
    mark++; 
    while (!augment(k)) { 
      int minc = 1000000000; 
      for (int i = 0; i < nm; i++) 
      if (vm[i] == mark) { 
        for (int j = 0; j < nh; j++) 
          if (vh[j] != mark && newdist[i][j] != 0 && newdist[i][j] < minc) { 
            minc = newdist[i][j]; 
          } 
      } 
      for (int i = 0; i < nm; i++) 
        if (vm[i] == mark) { 
          for (int j = 0; j < nh; j++) 
            newdist[i][j] -= minc; 
        } 
      for (int j = 0; j < nh; j++) 
        if (vh[j] == mark) { 
          for (int i = 0; i < nm; i++) 
            newdist[i][j] += minc; 
        } 
      mark++; 
    } 
  } 
  int ans =0 ; 
  for (int i = 0; i < nm; i++) 
  ans += dist[i][h[i]]; 
  return ans; 
} 