#ifndef EMITTER_H__
#define EMITTER_H__
#include <vector>
#include <ngl/Camera.h>
#include <ngl/Vec3.h>
#include <ngl/VertexArrayObject.h>
#pragma pack(push,1)

typedef struct Particle
{

	/// @brief the curent particle position
	//ngl::Vec3 m_pos;
	GLfloat m_px;
	GLfloat m_py;
	GLfloat m_pz;

	/// @brief the direction vector of the particle
	//ngl::Vec3 m_dir;
	GLfloat m_dx;
	GLfloat m_dy;
	GLfloat m_dz;
	/// @brief the current life value of the particle
	GLfloat m_currentLife;
	/// @brief gravity
	GLfloat m_gravity;
}Particle;

typedef struct GLParticle
{
	GLfloat px;
	GLfloat py;
	GLfloat pz;
//	GLfloat dx;
//	GLfloat dy;
//	GLfloat dz;
}GLParticle;



#pragma pack(pop)





class Emitter
{
public :

	/// @brief ctor
	/// @param _pos the position of the emitter
	/// @param _numParticles the number of particles to create
	Emitter( ngl::Vec3 _pos, int _numParticles, ngl::Vec3 *_wind );
	/// @brief a method to update each of the particles contained in the system
	void update();
	/// @brief a method to draw all the particles contained in the system
	void draw(const ngl::Mat4 &_rot);
	~Emitter();
  void setCam(ngl::Camera *_cam){m_cam=_cam;}
  ngl::Camera * getCam()const {return m_cam;}
  void setShaderName(const std::string &_n){m_shaderName=_n;}
  const std::string getShaderName()const {return m_shaderName;}
  void incTime(float _t){m_time+=_t;}
  void decTime(float _t){m_time-=_t;}
  void toggleExport(){ m_export^=true;}
  private :
	/// @brief the position of the emitter
	ngl::Vec3 m_pos;
	/// @brief the number of particles
	int m_numParticles;
	/// @brief the container for the particles
	Particle *m_particles;
	GLParticle *m_glparticles;
	/// @brief a wind vector
	ngl::Vec3 *m_wind;
  /// @brief the name of the shader to use
  std::string m_shaderName;
  /// @brief a pointer to the camera used for drawing
  ngl::Camera *m_cam;
  ngl::VertexArrayObject *m_vao;
  float m_time=0.8;
  bool m_export=false;
  void exportRib();

};


#endif

