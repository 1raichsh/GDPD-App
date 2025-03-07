#ifndef DFCAttr_h
#define DFCAttr_h 1

#include "StdAfx.h"

// DFCString
#include "DataStructure/DFCString.h"
// vector
#include "DataStructure/vector.h"


typedef vector<DFCAttr *, MBase::Allocator<DFCAttr *> > DFCAttrVEC;
#ifdef MCE_PRIVATE_PUBLIC
#define UTVIRTUALFUNCITON virtual
#else
#define UTVIRTUALFUNCITON
#endif

class MCESchema;
class DFCAttr 
{
public:
	typedef enum{NORMAL_ATTRIBUTE,		// ordinary attribute
		TRAN_ATTRIBUTE,			// transformation attribute
		ROLE_ATTRIBUTE,			// role attribute
		INDEPENDENT_ATTRIBUTE,	// independent attribute that does not go into schema
		DYNAMIC_ATTRIBUTE	// dynamic attribute created during Engine parsing
		, TOTAL_DIM_ATTRIBUTE	// total dim attribute
		, DERIVED_ATTRIBUTE //derived attribute, used for StarBelly Shared of Voice for now
	} DFCATTR_TYPE;

    typedef enum { PUSHDOWN_RESERVED = 0, PUSHDOWN_FAILED = 1, PUSHDOWN_SUCCEED = 2 }DFCATTR_ATTR_PUSHDOWN_STATUS;
    typedef set<Int32, less<Int32>, MBase::Allocator<Int32> > FORM_INDEX_SET;
    
    DFCAttr(MBase::Buffer*);
    static DFCAttr* UnserializeForSmartClient(ICDSSReadBlockStream* ipReadBlockStream, MBase::Buffer* ipBuffer, MCESchema* ipMCESchema = NULL);
    void UnserializeForSmartClient(ICDSSReadBlockStream* ipReadBlockStream, MCESchema* ipMCESchema = NULL);
    
    void CheckRefinement (MBase::Buffer *iBuffer, DFCSchemaInterface *iSchema, DFCBitVectorBase &iBVA, bool iFlag1, bool iFlag2, DFCBitVectorBase &iGroupby, bool &oRefined, bool &oGroupby, DFCBitVectorBase &oBVAr1, DFCBitVectorBase &oBVAr2, DFCBitVectorBase &ioCheckAttrs);
    bool HasProperRefinement (DFCBitVectorBase &iBVAt, DFCBitVectorBase &oBVM1, MBase::Buffer* iBuffer, DFCSchemaInterface *ipSchema);
    bool HasJointRefinement (DFCBitVectorBase &iBVAt, DFCBitVectorBase &oBVM1, MBase::Buffer* iBuffer, DFCSchemaInterface *ipSchema);
    bool ElimJtChild(DFCBitVectorBase& iBV, MBase::Buffer* iBuffer, DFCSchemaInterface *ipSchema);
    DFCBitVectorBase * GetRelativesVect (MBase::Buffer *ipBuffer, DFCSchemaInterface *ipSchema) const;

    //Getter Setter
    inline Int32 GetId() const          { return mAttrNbr; }
    inline void SetId(Int32 iNbr)       { mAttrNbr = iNbr; }
    
    inline DSS_ID* GetDSSID()           { return &mGuid; }
    inline DFCString GetName() const    { return mAttrName; };
    inline vector<DFCAttrGroup*, MBase::Allocator<DFCAttrGroup *> >& GetJointChildren() { return mJointChild; }
    
    inline bool IsQuality()             { return mJointChild.size(); }
    inline bool IsTotalDim() const      { return mIsTotalDim; }
    inline bool IsDynamicAttr()         { return mIsDynamicAttr; }
    
    virtual bool CheckIsDAOnRecursive() { return false;}
    DFCATTR_ATTR_PUSHDOWN_STATUS GetPushDownStatus() { return mDAPushDownStatus; }
    void SetDAPushDownStatus(DFCATTR_ATTR_PUSHDOWN_STATUS iDAPushdownStatus) { mDAPushDownStatus = iDAPushdownStatus; }
    //DE116321;hrwang@10-15-2018 virtual function for all of the DFCAttr to get push down form set.
    //now it is only implemented in DFCDerivedAttr class.
    virtual FORM_INDEX_SET* GetSucceedPushDownFormSet() { return nullptr; }
    virtual void SetGetSucceedPushDownForm(Int32 iFormIndex) { return; }
    
public:
    //fake ones. just help to build the project.
    void SerializeForSmartClient(ICDSSWriteBlockStream* ipWriteBlockStream, map<Int32, Int32, less<Int32>, MBase::Allocator<pair<const Int32, Int32> > >* ipAttrFilter = NULL) {}
    void Print(ostream&) {}

private:
    void CheckRefinementWithLevelCount (MBase::Buffer *iBuffer, DFCSchemaInterface *iSchema, DFCBitVectorBase &iBVA, bool iFlag1, bool iFlag2, DFCBitVectorBase &iGroupby, bool &oRefined, bool &oGroupby, DFCBitVectorBase &oBVAr1, DFCBitVectorBase &oBVAr2, Int32 iLevel);
    
private:
    MBase::Buffer* mpBuffer;
    Int32 mAttrNbr;
    bool mQualTag;
    DSS_ID mGuid;
    DFCString mAttrName;
    vector<DFCAttrGroup*, MBase::Allocator<DFCAttrGroup *> > mJointChild;
    bool mIsTotalDim;
    bool mIsDynamicAttr;
    DFCATTR_ATTR_PUSHDOWN_STATUS mDAPushDownStatus;
};

//## begin DFCAttr%32C3F7C603B6.postscript preserve=yes
//## end DFCAttr%32C3F7C603B6.postscript

// Class DFCAttr 

//## begin module%32C3F7C603B6.epilog preserve=yes
//## end module%32C3F7C603B6.epilog


#endif
