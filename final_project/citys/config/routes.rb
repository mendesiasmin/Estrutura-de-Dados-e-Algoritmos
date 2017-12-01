Rails.application.routes.draw do
  resources :distances
  resources :cities
  resources :map
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
  get 'map/dijkstra/:origin' => 'map#dijkstra', as: 'map_dijkstra'
end
