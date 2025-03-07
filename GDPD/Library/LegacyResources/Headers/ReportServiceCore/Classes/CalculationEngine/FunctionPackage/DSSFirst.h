//
//  DSSFirst.h
//  ReportServiceCore
//
//  Created by Yang Zhuo on 7/27/11.
//  Copyright 2011 Microstrategy. All rights reserved.
//


#ifndef CDSSFirst_h
#define CDSSFirst_h 1

#import "DSSNNGenericFunction.h"
#import "VariantCommonInclude.h"

class DSSFirst : public DSSNNGenericFunction
{
public:
    DSSFirst();
    ~DSSFirst();
    virtual HRESULT setProperty (Int32 Index, CComVariant *pValue);
    //    int Calculate(int nSize, CComVariant * pVec, EnumDSSDataType  iType, CComVariant * pResult, DSSDataFlag  * pFlag);
    //    int Calculate(int nSize, double *pVec, double *opResult, DSSDataFlag *pFlag);
    virtual HRESULT Calculate();
    virtual HRESULT SetInputParam (Int32 nParamIndex, Int32 nSize, EnumDSSDataType dataType, CComVariant *pData, DSSDataFlag *pFlag);
    virtual HRESULT GetOutput (Int32 nSize, Int32 *nDataSize, CComVariant *pData, DSSDataFlag *pFlag);
    virtual HRESULT GetOutputType (Int32 nSize, EnumDSSDataType *pInputType,
                               EnumDSSDataType *pOutputDataType, EnumDSSParameterType *pOutParamType);
    HRESULT getOutputType (EnumDSSDataType InputType, EnumDSSDataType * OutputType );
    virtual HRESULT GetInputParamType (Int32 nParamIndex, EnumDSSParameterType *pType);
    virtual HRESULT IsNullProcessable (bool *pCanProcessNULL);
    virtual int Clear ();
    
    virtual HRESULT GetOutput(Int32 nSize, Int32 *nDataSize,  double * pData,  DSSDataFlag * pFlag);
    virtual HRESULT GetOutputType(EnumDSSParameterType * pType);
    virtual HRESULT SetInputParam(Int32 nParamIndex, Int32 nSize, double * pData,  DSSDataFlag * pFlag);
    
    virtual bool IsNNFunctionOnly() {return true;}
private:
    CComVariant mResult;
    DSSDataFlag mResultFlag;
};



#endif
