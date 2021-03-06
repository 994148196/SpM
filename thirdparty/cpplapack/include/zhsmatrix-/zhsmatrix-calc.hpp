//=============================================================================
/*! return transposed zhsmatrix */
inline _zhsmatrix t(const zhsmatrix& mat)
{CPPL_VERBOSE_REPORT;
  zhsmatrix newmat(mat);
  
  const std::vector<zcomponent>::iterator newmat_data_end =newmat.data.end();
  for(std::vector<zcomponent>::iterator it=newmat.data.begin(); it!=newmat_data_end; it++){
    it->v =std::conj(it->v);
  }
  
  return _(newmat);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//=============================================================================
/*! return its conjugate matrix */
inline _zhsmatrix conj(const zhsmatrix& mat)
{CPPL_VERBOSE_REPORT;
  zhsmatrix newmat(mat);
  
  const std::vector<zcomponent>::iterator newmat_data_end =newmat.data.end();
  for(std::vector<zcomponent>::iterator it=newmat.data.begin(); it!=newmat_data_end; it++){
    it->v =std::conj(it->v);
  }
  
  return _(newmat);
}

//=============================================================================
/*! return its conjugate matrix */
inline _zhsmatrix conjt(const zhsmatrix& mat)
{CPPL_VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  WARNING_REPORT;
  std::cerr << "This function call has no effect since the matrix is Hermitian." << std::endl;
#endif//CPPL_DEBUG
  
  zhsmatrix newmat(mat);
  return _(newmat);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//=============================================================================
/*! search the index of element having the largest absolute value
  in 0-based numbering system */
inline void idamax(CPPL_INT& i, CPPL_INT& j, const zhsmatrix& mat)
{CPPL_VERBOSE_REPORT;
  std::vector<zcomponent>::const_iterator itx(mat.data.begin());
  double vmax =0.;
  
  const std::vector<zcomponent>::const_iterator mat_data_end =mat.data.end();
  for(std::vector<zcomponent>::const_iterator it=mat.data.begin(); it!=mat_data_end; it++){
    if( vmax < norm(it->v) ){
      vmax =norm(it->v);
      itx =it;
    }
  }
  
  i =itx->i;
  j =itx->j;
}

//=============================================================================
/*! return its largest absolute value */
inline comple damax(const zhsmatrix& mat)
{CPPL_VERBOSE_REPORT;
  std::vector<zcomponent>::const_iterator itx(mat.data.begin());
  double vmax =0.;
  
  const std::vector<zcomponent>::const_iterator mat_data_end =mat.data.end();
  for(std::vector<zcomponent>::const_iterator it=mat.data.begin(); it!=mat_data_end; it++){
    if( vmax < norm(it->v) ){
      vmax =norm(it->v);
      itx =it;
    }
  }
  
  return itx->v;
}
