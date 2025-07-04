// main_md.cpp
// g++ -std=c++17 -g particle.cpp main_visual_md.cpp -lsfml-window -lsfml-graphics -lsfml-system
#include "particle.h"
#include "integrator.h"
#include "collider.h"
#include "boundary.h"
#include <vector>

#include <SFML/Graphics.hpp>

void initial_conditions(std::vector<Particle> & particles);

int main(int argc, char **argv) {
  std::vector<Particle> bodies;
  bodies.resize(1); // only one particle for now

  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 100.8767;
  p["DT"] = 0.01;
  p["G"] = 0.0; //-9.81;

  // window
  const int WIDTH = 800, HEIGHT = 600;
  const float METERS_TO_PIXELS = 100.0f; // 200 pixels per meter
  
  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // Boundary conditions
  Boundary bc(2.345, 0.0, 0.0, 0.0, 0.1); // RMAX, CX, CY, CZ, EN

  // initial conditions and properties
  initial_conditions(bodies);
  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  std::cout << p["T0"] << "\t";
  bodies[0].print();
  std::cout << "\n";

  // --- VISUALIZATION SETUP ---
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "C++ Simulation & Visualization");
  window.setFramerateLimit(120);
  sf::CircleShape particle_shape(bodies[0].rad);
  particle_shape.setFillColor(sf::Color::Cyan);
  particle_shape.setOrigin(0, 0);

  // Time iteration
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter && window.isOpen(); ++ii) {
    // check close event
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    // md simul
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
    bc.apply(bodies);

    // 2. Run the C++ visualization
    window.clear(sf::Color::Black);
    for (const auto& p : bodies) {
      float pixel_radius = p.rad * METERS_TO_PIXELS;
      // Set the radius for this specific particle, scaled to pixels
      particle_shape.setRadius(pixel_radius);
      // Center the origin so setPosition() refers to the center of the circle
      particle_shape.setOrigin(pixel_radius, pixel_radius);

      // Convert world coordinates to screen coordinates
      sf::Vector2f screen_pos;
      screen_pos.x = (WIDTH / 2.0f) + (p.R[0] * METERS_TO_PIXELS);
      // Flip the Y-axis: (HEIGHT - world_y_in_pixels)
      screen_pos.y = (HEIGHT / 2.0f) - (p.R[2] * METERS_TO_PIXELS);
      
      particle_shape.setPosition(screen_pos);
      window.draw(particle_shape);
    }
    window.display();

    // // print local info
    // double time = p["T0"] + ii*p["DT"];
    // std::cout << time << "\t";
    // bodies[0].print();
    // std::cout << "\n";
  }

  return 0;
}

void initial_conditions(std::vector<Particle> & particles)
{
  particles[0].R[2] = 0.987;  // z is upwards, x to the right
  particles[0].V[0] = 4.9876;//12.987; // z is upwards, x to the right
  particles[0].V[2] = 0.0; //4.9876; //3.987; // z is upwards, x to the right
  particles[0].rad  = 0.103;
  particles[0].mass = 0.337;
}
