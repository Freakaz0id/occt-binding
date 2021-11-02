#include <iostream>
#include <pybind11/pybind11.h>
#include <STEPControl_Reader.hxx>
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>

namespace py = pybind11;

float some_fn(float arg1, float arg2) {
    return arg1 + arg2;
}

float get_volume(const char* filePath) {
    std::cout << "Reading file: " << filePath << std::endl;
    
    STEPControl_Reader reader;
	//IFSelect_ReturnStatus stat = reader.ReadFile("/home/spark/Documents/pybind-example/models/Ventilator.stp");
	IFSelect_ReturnStatus stat = reader.ReadFile(filePath);
	IFSelect_PrintCount mode = IFSelect_ListByItem;
	reader.PrintCheckLoad(false, mode);

	Standard_Integer NbRoots = reader.NbRootsForTransfer();  //Transfer whole file
	Standard_Integer num = reader.TransferRoots();

	Standard_Integer NbTrans = reader.TransferRoots();
	TopoDS_Shape result = reader.OneShape();
	TopoDS_Shape shape = reader.Shape();

	GProp_GProps gprops;
	BRepGProp::VolumeProperties(shape, gprops);
	double volume = gprops.Mass();

	std::cout << "Roots: " << NbRoots << std::endl;
	std::cout << "TransferRoots: " << NbTrans << std::endl;
	std::cout << "Number of Parts: " << num << std::endl;
	std::cout << "Volume: " << volume << " mm³" << std::endl;
    return volume;
}

PYBIND11_MODULE(spark, handle) {
    handle.doc() = "This is a doc";
    handle.def("some_fn", &some_fn);
    handle.def("get_volume", &get_volume);
}