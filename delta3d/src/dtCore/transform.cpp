#include <prefix/dtcoreprefix-src.h>
#include "dtCore/transform.h"
#include "dtUtil/matrixutil.h"
#include "dtUtil/polardecomp.h"
#include "dtUtil/deprecationmgr.h"

using namespace dtCore;

Transform::Transform( float tx, float ty, float tz, float h, float p, float r, float sx, float sy, float sz )
{
   Set( tx, ty, tz, h, p, r, sx, sy, sz );
}

Transform::Transform( const Transform& that )
{
   SetTranslation( that.mTranslation );
   SetRotation( that.mRotation );
   SetScale( that.mScale );
}

Transform::~Transform()
{
}

void Transform::Set( float tx, float ty, float tz, float h, float p, float r, float sx, float sy, float sz )
{
   osg::Vec3 xyz( tx, ty, tz );
   osg::Vec3 hpr( h, p, r );
   osg::Vec3 scale( sx, sy, sz );

   osg::Matrix rotation;
   dtUtil::MatrixUtil::HprToMatrix( rotation, hpr );

   Set( xyz, rotation, scale );
}

void Transform::Set( const osg::Vec3& xyz, const osg::Matrix& rotation, const osg::Vec3& scale )
{
   SetTranslation( xyz );
   SetRotation( rotation );
   SetScale( scale );
}

void Transform::Set(const osg::Vec3& xyz, const osg::Vec3& hpr, const osg::Vec3& scale)
{
   osg::Matrix rotation;
   dtUtil::MatrixUtil::HprToMatrix( rotation, hpr );

   Set( xyz, rotation, scale );
}

void Transform::Set( const osg::Matrix& mat )
{
   osg::Matrix rotation, scale;
   osg::Vec3 translation;
   osg::Vec3 hpr;

   //dtUtil::PolarDecomp::Decompose( mat, rotation, scale, translation );
   dtUtil::MatrixUtil::MatrixToHpr( hpr, mat );

   SetTranslation( mat.getTrans() );
   SetRotation( hpr );
   mScale.set( mat.getScale() );   

}

void Transform::SetRotation( float h, float p, float r )
{
   SetRotation( osg::Vec3( h, p, r ) );
}

void Transform::SetRotation( const osg::Vec3& hpr )
{
   osg::Matrix rotation;

   dtUtil::MatrixUtil::HprToMatrix( rotation, hpr );

   SetRotation( rotation );
}

void Transform::Get( float& tx, float& ty, float& tz, float& h, float& p, float& r, float &sx, float &sy, float &sz ) const
{
   tx = mTranslation[0];
   ty = mTranslation[1];
   tz = mTranslation[2];

   GetRotation( h, p, r );

   sx = mScale[0];
   sy = mScale[1];
   sz = mScale[2];
}

void Transform::Get( osg::Vec3& xyz, osg::Matrix& rotation, osg::Vec3& scale ) const
{
   xyz.set( mTranslation );
   rotation.set( mRotation );
   scale.set( mScale );
}

void Transform::Get( osg::Matrix& matrix ) const
{
   osg::Matrix fullMatrix = mRotation * osg::Matrix::scale( mScale );
   dtUtil::MatrixUtil::SetRow( fullMatrix, mTranslation, 3 );

   matrix.set(fullMatrix);
}

void Transform::Get( osg::Vec3& xyz, osg::Vec3& hpr, osg::Vec3& scale ) const
{
   xyz.set(mTranslation);
   GetRotation(hpr);
   scale.set(mScale);
}

void Transform::GetTranslation( float& tx, float& ty, float& tz ) const
{
   tx = mTranslation[0];
   ty = mTranslation[1];
   tz = mTranslation[2];
}

void Transform::GetRotation( float& h, float& p, float& r ) const
{
   osg::Vec3 hpr;
   dtUtil::MatrixUtil::MatrixToHpr( hpr, mRotation );

   h = hpr[0];
   p = hpr[1];
   r = hpr[2];
}

void Transform::GetRotation( osg::Vec3& hpr ) const
{
   dtUtil::MatrixUtil::MatrixToHpr( hpr, mRotation );
}


void Transform::GetScale( float& sx, float& sy, float& sz ) const
{
   sx = mScale[0];
   sy = mScale[1];
   sz = mScale[2];
}

void Transform::SetLookAt( const osg::Vec3& xyz, const osg::Vec3& lookAtXYZ, const osg::Vec3& upVec )
{
   osg::Matrix mat;
   osg::Vec3 x,y,z;

   y = lookAtXYZ - xyz;
   z = upVec;
   x = y ^ z;
   z = x ^ y;

   x.normalize();
   y.normalize();
   z.normalize();
   
   dtUtil::MatrixUtil::SetRow(mat, x, 0);
   dtUtil::MatrixUtil::SetRow(mat, y, 1);
   dtUtil::MatrixUtil::SetRow(mat, z, 2);

   SetRotation( mat );
   SetTranslation( xyz );

}

void Transform::SetLookAt(float posX, float posY, float posZ,
                          float lookAtX, float lookAtY, float lookAtZ,
                          float upVecX, float upVecY, float upVecZ)
{
   osg::Vec3 xyz( posX, posY, posZ );
   osg::Vec3 lookAt( lookAtX, lookAtY, lookAtZ );
   osg::Vec3 upVec( upVecX, upVecY, upVecZ );

   SetLookAt( xyz, lookAt, upVec );
}

bool Transform::EpsilonEquals( const Transform& transform, float epsilon ) const
{
   osg::Matrix thisMatrix, thatMatrix;

   Get( thisMatrix );
   transform.Get( thatMatrix );

   for( int i = 0; i < 4; i++ )
      for( int j = 0; j < 4; j++ )
         if( fabs( thisMatrix(i,j) - thatMatrix(i,j) ) > epsilon)
            return false;

   return true;
}

Transform & Transform::operator=(const Transform & rhs)
{
   if (this == &rhs) return *this;

   SetTranslation( rhs.mTranslation );
   SetRotation( rhs.mRotation );
   SetScale( rhs.mScale );
   
   return *this;
}

bool Transform::operator==(const Transform & rhs)
{
   if (this == &rhs) return true;

   return EpsilonEquals( rhs, 0.0f );
}
