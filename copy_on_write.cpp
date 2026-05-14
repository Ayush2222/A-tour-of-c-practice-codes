class Image{
	public:
		Image(const Image& a); //copy constructor
		void write_block(Descriptor);
	private:
		Representation* clone();
		Representation* rep;
		Image* reference{nullptr};
		mutable int reference_count{0};
};


Image:: Image(const Image& a) :rep{a.rep}{
	if(a.reference==nullptr){
		reference = a;
	}else{
		reference = a.reference;	
	}
	a.reference_count++;
}
void Image::write_block(Descriptor d){
	if(reference_count!=0 && reference==nullptr){
		Image im = new Image();//can be Image im; on stack also but loss after returning from the function;

		im.rep = clone();
		std::swap(im, *this);
	}else if(reference!=nullptr){
		if(reference->reference_count>=1){
			rep = clone();
			reference->reference_count--;	
			reference = nullptr;
		}else{
			reference = nullptr;
		}
	}
}
